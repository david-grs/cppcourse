#include "game_controller.h"

#include <boost/algorithm/string.hpp>
#include <cinder/Text.h>
#include <fstream>
#include <algorithm>

void GameController::Setup()
{
	mGameWorld = CreateGameWorld();
	SetupControllers(mGameWorld);
}

void GameController::Update(double elapsedTime)
{
	double timeDelta = elapsedTime - mTimeSinceLastUpdate;
	mTimeSinceLastUpdate = elapsedTime;

	mCurtainController->Update(elapsedTime);

	if (mGameState == ACTIVE)
	{
		for (auto& ghostController : mGhostControllers)
		{
			ghostController->Update(elapsedTime);
		}

		mPacmanController->Update(elapsedTime);

		mTimeSinceGameActive += std::chrono::duration<double>(timeDelta);
		if (!mGhostsReleased && mTimeSinceGameActive > mConfig.RELEASE_GHOSTS)
		{
			ReleaseGhosts();
		}
		if (IsGameOver())
		{
			UpdateGameState(OVER);
		}
	}
}

void GameController::Draw()
{
	if (mGameState == ACTIVE)
	{
		for (auto& ghostController : mGhostControllers)
		{
			ghostController->Draw();
		}
		mPacmanController->Draw();
	}
	mCurtainController->Draw();
}

void GameController::KeyDown(Direction direction)
{
	mPacmanController->KeyDown(direction);
}

GameWorld GameController::CreateGameWorld()
{
	GameWorld gameWorld;
	Grid grid;

	int fieldRow = mConfig.MAP_START_ROW;
	std::ifstream inFile(mConfig.MAP_FILE_NAME);
	
	for (std::string line; getline(inFile, line);)
	{
		int fieldColumn = mConfig.MAP_START_COLUMN;
		std::vector<std::string> tokens;
		boost::split(tokens, line, boost::is_any_of(","));
		std::vector<FieldPtr> gameFields;

		for (auto token : tokens)
		{
			Point center(fieldRow, fieldColumn);
			Point gridPosition{ static_cast<int>(grid.size()), static_cast<int>(gameFields.size()) };

			auto it = stringToField.find(token);
			if (it != stringToField.end())
			{
				switch (it->second)
				{
				case WALL:
					gameFields.push_back(std::make_unique<Wall>(center, gridPosition, mConfig));
					break;
				case TMP_WALL:
					gameFields.push_back(std::make_unique<TemporaryWall>(center, gridPosition, mConfig));
					break;
				case BASIC:
					gameFields.push_back(std::make_unique<BasicField>(center, gridPosition, mConfig));
					break;
				case COIN:
					gameFields.push_back(std::make_unique<Coin>(center, gridPosition, mConfig));
					break;
				case PACMAN:
					gameFields.push_back(std::make_unique<EmptyField>(center, gridPosition, mConfig));
					gameWorld.mPacman = std::make_unique<Pacman>(center, gridPosition, mConfig);
					break;
				case GHOST:
					gameFields.push_back(std::make_unique<EmptyField>(center, gridPosition, mConfig));
					gameWorld.mGhosts.push_back(std::make_unique<Ghost>(center, gridPosition, mConfig));
					break;
				default: // EMPTY
					gameFields.push_back(std::make_unique<EmptyField>(center, gridPosition, mConfig));
					break;
				}
			}
			fieldColumn += mConfig.FIELD_SIZE + mConfig.FIELD_OFFSET;
		}
		grid.push_back(std::move(gameFields));
		fieldRow += mConfig.FIELD_SIZE + mConfig.FIELD_OFFSET;
	}
	
	gameWorld.mGameMap.mBoundaries = GetBoundaries(grid);
	gameWorld.mGameMap.mGrid = std::make_shared<Grid>(std::move(grid));
	return gameWorld;
}

Boundaries GameController::GetBoundaries(const Grid& grid)
{
	Boundaries boundaries;
	int maxRows = grid.size();
	int maxCols = grid.at(0).size();
	boundaries.mGrid = Point(maxRows, maxCols);

	int mapRowOffset = static_cast<int>(mConfig.MAP_START_ROW - mConfig.FIELD_SIZE / 2);
	int mapColOffset = static_cast<int>(mConfig.MAP_START_COLUMN - mConfig.FIELD_SIZE / 2);
	int maxPixelRows = (maxRows * mConfig.FIELD_SIZE) + ((maxRows - 1) * mConfig.FIELD_OFFSET) + mapRowOffset;
	int maxPixelCols = (maxCols * mConfig.FIELD_SIZE) + ((maxCols - 1) * mConfig.FIELD_OFFSET) + mapColOffset;
	
	boundaries.mMapPixelsMax = Point(maxPixelRows, maxPixelCols);
	boundaries.mMapPixelsMin = Point(mapRowOffset, mapColOffset);

	return boundaries;
}

void GameController::SetupControllers(GameWorld& gameWorld)
{
	mCurtainController = std::make_unique<GameCurtainController>(mConfig, gameWorld.mGameMap);
	
	mPacmanController = std::make_unique<PacmanController>(mConfig, gameWorld.mPacman, gameWorld.mGameMap);
	mPacmanController->SetScoreUpdateCallback([this](int score)
	{
		UpdateScore(score);
	});

	for (auto& ghost : gameWorld.mGhosts)
	{
		mGhostControllers.push_back(std::make_unique<GhostController>(mConfig, ghost, gameWorld.mGameMap));
	}
}

void GameController::UpdateGameState(GameState gameState)
{
	if (mGameState != OVER)
	{
		for (auto& ghostController : mGhostControllers)
		{
			ghostController->UpdateGameState(gameState);
		}

		mPacmanController->UpdateGameState(gameState);
		mCurtainController->UpdateGameState(gameState);
		mGameState = gameState;
	}
}

void GameController::ReleaseGhosts()
{
	for (auto& row : *(mGameWorld.mGameMap.mGrid))
	{
		for (auto& field : row)
		{
			field->SetIsVisitable(true);
		}
	}
	mGhostsReleased = true;
}

bool GameController::IsGameOver()
{
	const auto pacmanGridPosition = mPacmanController->GetObjectPosition();
	return std::any_of(mGhostControllers.begin(), mGhostControllers.end(), [&](const GhostControllerPtr& ghostController)
	{
		return !(pacmanGridPosition != ghostController->GetObjectPosition());
	});
}