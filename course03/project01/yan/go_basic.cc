#include "go_basic.h"

bool Position::isValid() const
{
	return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

Component::Component(const Position& element)
{
	mElements.clear();
	add(element);
}

Component::Component(const std::set<Position>& elements)
{
	mElements.clear();
	add(elements);
}

void Component::add(Position element)
{
	// This function deliberately uses a copy of element instead of a reference
	// to avoid unintentional changes of the reference in a self referencing loop
	// eg. in Scoring::findComponentFromGameState
	if (contains(element))
		return;

	if (element.isValid())
		mElements.insert(element);

	if (onBoundary(element))
		mBoundary.erase(element);

	const std::array<Position, 4> pos{Position(-1, 0), Position(1, 0), Position(0, -1), Position(0, 1)};

	for (const Position& p: pos)
	{
		Position neighbour = element + p;
		if (neighbour.isValid() && !contains(neighbour))
			mBoundary.insert(neighbour);
	}

}

void Component::add(const std::set<Position>& elements)
{
	for (auto element: elements)
		add(element);
}

bool Component::contains(const Position& element) const
{
	if (mElements.find(element) == mElements.end())
		return false;
	return true;
}

bool Component::onBoundary(const Position& element) const
{
	if (mBoundary.find(element) == mBoundary.end())
		return false;
	return true;
}

const std::set<Position>& Component::getElements() const
{
	return mElements;
}

const std::set<Position>& Component::getBoundary() const
{
	return mBoundary;
}

void Component::merge(const Component& other)
{
	for (const Position& element : other.getElements())
	{
		mElements.insert(element);
		if (onBoundary(element))
			mBoundary.erase(element);
	}

	for (const Position& element : other.getBoundary())
	{
		if (!contains(element))
			mBoundary.insert(element);
	}
}

bool Component::isValid() const
{
	// Test for non-emptiness
	if (mElements.size() == 0)
		return false;

//	// Test that all elements are valid
//	for (const Position& element : mElements)
//	{
//		if (!element.isValid())
//			return false;
//	}

//	for (const Position& element : mBoundary)
//	{
//		if (!element.isValid())
//			return false;
//	}
	return true;
}

Position PASS_POSITION{-1, -1};

GoBasic::GoBasic()
{
	restart();
}

void GoBasic::setCell(SIDE value, int x, int y)
{
	mCells[x][y] = value;
}

void GoBasic::setCell(SIDE value, const Position& pos)
{
	setCell(value, pos.x, pos.y);
}

GoBasic::SIDE GoBasic::getCell(int x, int y) const
{
	return mCells[x][y];
}

GoBasic::SIDE GoBasic::getCell(const Position& pos) const
{
	return getCell(pos.x, pos.y);
}

GoBasic::SIDE GoBasic::getCurrentPlayer() const
{
	return mCurrentPlayer;
}

bool GoBasic::hasFreeCell(const std::shared_ptr<Component>& component) const
{
	const std::set<Position>& boundary = component->getBoundary();
	bool hasFreeCell = false;
	for (const Position& cell : boundary)
	{
		if (getCell(cell) == SIDE::NONE)
		{
			hasFreeCell = true;
			break;
		}
	}
	return hasFreeCell;
}

void GoBasic::switchSide()
{
	if (mCurrentPlayer == SIDE::BLACK)
	{
		mCurrentPlayer = SIDE::WHITE;
	}
	else
	{
		mCurrentPlayer = SIDE::BLACK;
	}
}

void GoBasic::restart()
{
	mCurrentPlayer = SIDE::BLACK;
	mMoves.clear();
	mBlackComponents.clear();
	mWhiteComponents.clear();
	mSingleCapturedPositionInLastMove = PASS_POSITION;
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			mCells[i][j] = SIDE::NONE;
		}
	}
}

GoBasic::STATE GoBasic::makeMove(const Position& pos)
{
	if (!pos.isValid() || getCell(pos) != SIDE::NONE)
		return STATE::OCCUPIED;

	// temporarily placing piece on cell
	setCell(mCurrentPlayer, pos);

	std::set<std::shared_ptr<Component>>& ownComponents = (mCurrentPlayer == SIDE::BLACK) ? mBlackComponents : mWhiteComponents;
	std::set<std::shared_ptr<Component>>& opponentComponents = (mCurrentPlayer == SIDE::BLACK) ? mWhiteComponents : mBlackComponents;

	// check if opponent pieces are captured
	std::set<std::shared_ptr<Component>> opponentComponentsToRemove;
	for (const std::shared_ptr<Component>& component : opponentComponents)
	{
		if (component->onBoundary(pos))
		{
			if (!hasFreeCell(component))
			{
				const std::set<Position>& elements = component->getElements();
				for (const Position& cell : elements)
					setCell(SIDE::NONE, cell);

				opponentComponentsToRemove.insert(component);
			}
		}
	}

	// if only one piece was captured, note down the position

	Position singleCapturedPosition = PASS_POSITION;
	if (opponentComponentsToRemove.size() == 1)
	{
		const std::set<Position>& elements = (*opponentComponentsToRemove.begin())->getElements();
		if (elements.size() == 1)
			singleCapturedPosition = *elements.begin();

	}

	for (const std::shared_ptr<Component>& component : opponentComponentsToRemove)
		opponentComponents.erase(component);

	// create new component by finding all components that border the new piece,
	// and making a set of old components to remove

	auto newComponent = std::make_shared<Component>(pos);
	std::set<std::shared_ptr<Component>> ownComponentsToRemove;
	for (const std::shared_ptr<Component>& component : ownComponents)
	{
		if (component->onBoundary(pos))
		{
			newComponent->merge(*component);
			ownComponentsToRemove.insert(component);
		}
	}

	// check if new component is valid, if it is, add it to own components, otherwise, undo move.

	if (!hasFreeCell(newComponent))
	{
		setCell(SIDE::NONE, pos);
		return STATE::ILLEGAL;
	}
	else if (pos == mSingleCapturedPositionInLastMove)
	{
		setCell(SIDE::NONE, pos);
		setCell(mCurrentPlayer == SIDE::BLACK? SIDE::WHITE : SIDE::BLACK, singleCapturedPosition);
		std::shared_ptr<Component> capturedPiece = std::make_shared<Component>(singleCapturedPosition);
		opponentComponents.insert(capturedPiece);
		return STATE::ILLEGAL;
	}
	else
	{
		for (const std::shared_ptr<Component>& component : ownComponentsToRemove)
		{
			ownComponents.erase(component);
		}
		ownComponents.insert(newComponent);
		mMoves.push_back(pos);
		switchSide();
		mSingleCapturedPositionInLastMove = singleCapturedPosition;
		return STATE::SUCCESS;
	}
}

GoBasic::STATE GoBasic::pass()
{
	mMoves.push_back(PASS_POSITION);
	switchSide();
	return STATE::SUCCESS;
}

GoBasic::STATE GoBasic::undo()
{
	if (mMoves.size() == 0)
		return STATE::SUCCESS;

	std::vector<Position> moves = mMoves;
	moves.erase(--moves.end());
	restart();
	for (Position move : moves)
	{
		if (move == PASS_POSITION)
			pass();
		else
			makeMove(move);
	}
	return STATE::SUCCESS;
}
