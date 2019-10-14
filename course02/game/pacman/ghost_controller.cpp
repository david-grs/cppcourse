#include "ghost_controller.h"
#include <stdlib.h>

void GhostController::Draw()
{
	if (mGameState == ACTIVE)
	{
		mGhost->Draw();
	}
}

void GhostController::Update(double elapsedTime)
{
	auto updateNow = std::chrono::duration<double>(elapsedTime);
	auto timeDelta = updateNow - mLastUpdate;
	mUpdateInterval += std::chrono::duration_cast<Milliseconds>(timeDelta);
	mLastUpdate = updateNow;

	if (mGameState == ACTIVE && mUpdateInterval >= mConfig.PACMAN_UPDATE_INTERVAL)
	{
		mUpdateInterval = 0ms;
		Direction direction = GetRandomDirection();
		GameField* nextField = GetNextField(direction);

		if (GhostAllowedToEnterNextField(direction, nextField))
		{
			mGhost->SetDirection(direction);
			if (GhostIsInNextField(nextField))
			{
				mGhost->SetCenter(nextField->GetCenter());
				mGhost->SetGridPosition(nextField->GetGridPosition());
			}
			else
			{
				mGhost->MakeStep();
			}
		}
		else if (GhostCanMoveInItsOwnField())
		{
			mGhost->MakeStep();
		}
		
	}
}

bool GhostController::GhostAllowedToEnterNextField(Direction direction, GameField* nextField)
{
	if (nextField)
	{
		if (nextField->GetGridPosition() != mGhost->GetGridPosition())
		{
			auto pacmanPixelPosition = mGhost->GetCenter();

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

bool GhostController::GhostCanMoveInItsOwnField()
{
	auto pacmanPixelPosition = mGhost->GetCenter();
	auto pacmanGridPosition = mGhost->GetGridPosition();
	auto currentField = mGrid->at(pacmanGridPosition.mRow).at(pacmanGridPosition.mColumn).get();
	switch (mGhost->GetDirection())
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

GameField* GhostController::GetNextField(Direction direction)
{
	auto ghostGridPosition = mGhost->GetGridPosition();
	if (direction == LEFT)
	{
		if (ghostGridPosition.mColumn <= 0)
		{
			return mGrid->at(ghostGridPosition.mRow).at(mBoundaries.mGrid.mColumn - 1).get();;
		}
		else
		{
			return mGrid->at(ghostGridPosition.mRow).at(ghostGridPosition.mColumn - 1).get();
		}
	}
	else if (direction == RIGHT)
	{
		if (ghostGridPosition.mColumn >= mBoundaries.mGrid.mColumn - 1)
		{
			return mGrid->at(ghostGridPosition.mRow).at(0).get();;
		}
		else
		{
			return mGrid->at(ghostGridPosition.mRow).at(ghostGridPosition.mColumn + 1).get();
		}
	}
	else if (direction == UP)
	{
		if (ghostGridPosition.mRow <= 0)
		{
			return mGrid->at(mBoundaries.mGrid.mRow - 1).at(ghostGridPosition.mColumn).get();
		}
		else
		{
			return mGrid->at(ghostGridPosition.mRow - 1).at(ghostGridPosition.mColumn).get();
		}
	}
	else if (direction == DOWN)
	{
		if (ghostGridPosition.mRow >= mBoundaries.mGrid.mRow - 1)
		{
			return mGrid->at(0).at(ghostGridPosition.mColumn).get();
		}
		else
		{
			return mGrid->at(ghostGridPosition.mRow + 1).at(ghostGridPosition.mColumn).get();
		}
	}
	return nullptr;
}

bool GhostController::GhostIsInNextField(GameField* nextField)
{
	if (mGhost->GetGridPosition() != nextField->GetGridPosition())
	{
		auto pacmanPixelPosition = mGhost->GetCenter();
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

Direction GhostController::GetRandomDirection()
{
	return Direction(std::rand() % 5);
}