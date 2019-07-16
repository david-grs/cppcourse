#pragma once

#include <array>
#include <vector>
#include <set>
#include <memory>

const int BOARD_SIZE = 19;

struct Position : std::pair<int, int>
{
	using std::pair<int, int>::pair;

	int x = first;
	int y = second;

	bool isValid() const;

	friend Position operator+(Position a, Position b)
	{
		return Position(a.x + b.x, a.y + b.y);
	}
};

class Component
{
public:
	Component(const Position&  element);
	Component(const std::set<Position>&  elements);

	void add(Position  element);
	void add(const std::set<Position>&  elements);

	bool contains(const Position& element) const;
	bool onBoundary(const Position&  element) const;

	const std::set<Position>& getElements() const;
	const std::set<Position>& getBoundary() const;

	void merge(const Component& other);

	bool isValid() const;

	friend bool operator==(const Component& a, const Component& b)
	{
		return a.mElements == b.mElements;
	}

	friend bool operator<(const Component& a, const Component& b)
	{
		return a.mElements < b.mElements;
	}

private:
	std::set<Position> mElements;
	std::set<Position> mBoundary;
};

class GoBasic
{
public:
	enum class SIDE
	{
		NONE,
		BLACK,
		WHITE
	};

	enum class STATE
	{
		SUCCESS,
		OCCUPIED,
		ILLEGAL
	};

	GoBasic();

	void setCell(SIDE value, int x, int y);
	void setCell(SIDE value, const Position& pos);
	SIDE getCell(int x, int y) const;
	SIDE getCell(const Position& pos) const;
	SIDE getCurrentPlayer() const;
	bool hasFreeCell(const std::shared_ptr<Component>& component) const;
	void switchSide();
	void restart();
	STATE makeMove(const Position& pos);
	STATE pass();
	STATE undo();
	const std::set<std::shared_ptr<Component>>& getBlackComponents() const
	{
		return mBlackComponents;
	}
	const std::set<std::shared_ptr<Component>>& getWhiteComponents() const
	{
		return mWhiteComponents;
	}

private:
	std::array<std::array<SIDE, BOARD_SIZE>, BOARD_SIZE> mCells;
	SIDE mCurrentPlayer;
	std::vector<Position> mMoves;
	std::set<std::shared_ptr<Component>> mBlackComponents;
	std::set<std::shared_ptr<Component>> mWhiteComponents;
	Position mSingleCapturedPositionInLastMove;
};
