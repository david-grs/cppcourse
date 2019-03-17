#include "pacman_controller.h"

void PacmanController::Draw()
{
	if (mGameState == ACTIVE)
	{
		mPacman->Draw();
	}
}

void PacmanController::Update(double elapsedTime)
{	
	auto updateNow = std::chrono::duration<double>(elapsedTime);
	auto timeDelta = updateNow - mLastUpdate;
	mUpdateInterval += std::chrono::duration_cast<Milliseconds>(timeDelta);
	mPacman->UpdateMouth(timeDelta.count());

	if (mGameState == ACTIVE && mUpdateInterval >= mConfig.PACMAN_UPDATE_INTERVAL)
	{
		Direction direction = mPacman->GetDirection();
		GameField* nextField = GetNextField(direction);

		if (PacmanAllowedToEnterNextField(direction, nextField))
		{
			if (PacmanIsInNextField(nextField))
			{
				mUpdateScore(nextField->GetPoints());
				nextField->UnsetPoints();
				mPacman->SetCenter(nextField->GetCenter());
				mPacman->SetGridPosition(nextField->GetGridPosition());
			}
			else
			{
				mPacman->MakeStep();
			}
		}
		else if (PacmanCanMoveInItsOwnField())
		{
			mPacman->MakeStep();
		}
		mUpdateInterval = 0ms;
	}
	mLastUpdate = updateNow;
}

void PacmanController::KeyDown(Direction direction)
{
	GameField* nextField = GetNextField(direction);
	if (nextField && PacmanAllowedToEnterNextField(direction, nextField))
	{
		mPacman->SetDirection(direction);
	}
}

bool PacmanController::PacmanAllowedToEnterNextField(Direction direction, GameField* nextField)
{
	if (nextField)
	{
		if (nextField->GetGridPosition() != mPacman->GetGridPosition())
		{
			auto pacmanPixelPosition = mPacman->GetCenter();

			if (direction == LEFT || direction == RIGHT)
			{
				return nextField->IsVisitable() &&
					pacmanPixelPosition.mRow == nextField->GetCenter().mRow;
			}
			else if (direction == UP || direction == DOWN)
			{
				return nextField->IsVisitable() &&
					pacmanPixelPosition.mColumn == nextField->GetCenter().mColumn;
			}
		}
	}
	return false;
}

bool PacmanController::PacmanCanMoveInItsOwnField()
{
	auto pacmanPixelPosition = mPacman->GetCenter();
	auto pacmanGridPosition = mPacman->GetGridPosition();
	auto currentField = mGrid->at(pacmanGridPosition.mRow).at(pacmanGridPosition.mColumn).get();
	switch (mPacman->GetDirection())
	{
	case LEFT:
		return pacmanPixelPosition.mColumn > currentField->GetCenter().mColumn;
	case RIGHT:
		return pacmanPixelPosition.mColumn < currentField->GetCenter().mColumn;
	case UP:
		return pacmanPixelPosition.mRow > currentField->GetCenter().mRow;
	case DOWN:
		return pacmanPixelPosition.mRow < currentField->GetCenter().mRow;
	default:
		return false;
	}
}

GameField* PacmanController::GetNextField(Direction direction)
{
	auto pacmanGridPosition = mPacman->GetGridPosition();

	if (direction == LEFT)
	{
		if (pacmanGridPosition.mColumn <= 0)
		{
			return mGrid->at(pacmanGridPosition.mRow).at(mBoundaries.mGrid.mColumn - 1).get();
		}
		else
		{
			return mGrid->at(pacmanGridPosition.mRow).at(pacmanGridPosition.mColumn - 1).get();
		}
	}
	else if (direction == RIGHT)
	{
		if (pacmanGridPosition.mColumn >= mBoundaries.mGrid.mColumn - 1)
		{
			return mGrid->at(pacmanGridPosition.mRow).at(0).get();;
		}
		else
		{
			return mGrid->at(pacmanGridPosition.mRow).at(pacmanGridPosition.mColumn + 1).get();
		}
	}
	else if (direction == UP)
	{
		if (pacmanGridPosition.mRow <= 0)
		{
			return mGrid->at(mBoundaries.mGrid.mRow - 1).at(pacmanGridPosition.mColumn).get();
		}
		else
		{
			return mGrid->at(pacmanGridPosition.mRow - 1).at(pacmanGridPosition.mColumn).get();
		}
	}
	else if (direction == DOWN)
	{
		if (pacmanGridPosition.mRow >= mBoundaries.mGrid.mRow - 1)
		{
			return mGrid->at(0).at(pacmanGridPosition.mColumn).get();
		}
		else
		{
			return mGrid->at(pacmanGridPosition.mRow + 1).at(pacmanGridPosition.mColumn).get();
		}
	}
	return nullptr;
}

bool PacmanController::PacmanIsInNextField(GameField* nextField)
{
	if (mPacman->GetGridPosition() != nextField->GetGridPosition())
	{
		auto pacmanPixelPosition = mPacman->GetCenter();
		if (pacmanPixelPosition.mRow < mBoundaries.mMapPixelsMin.mRow ||
			mBoundaries.mMapPixelsMax.mRow < pacmanPixelPosition.mRow ||
			pacmanPixelPosition.mColumn < mBoundaries.mMapPixelsMin.mColumn ||
			mBoundaries.mMapPixelsMax.mColumn < pacmanPixelPosition.mColumn)
		{
			return true;
		}

		auto nextFieldCenter = nextField->GetCenter();
		double fieldWidth = mConfig.FIELD_SIZE / 2.0;

		if (nextFieldCenter.mRow == pacmanPixelPosition.mRow)
		{
			return abs(nextFieldCenter.mColumn - pacmanPixelPosition.mColumn) < fieldWidth;
		}
		else if (nextFieldCenter.mColumn == pacmanPixelPosition.mColumn)
		{
			return abs(nextFieldCenter.mRow - pacmanPixelPosition.mRow) < fieldWidth;
		}
	}
	return true;
}
