#pragma once

#include "config.h"
#include "types.h"
#include "pacman.h"

class GameCurtainController : public IController
{
public:
	GameCurtainController(const Config& config, GameMap& gameMap)
		:
		mConfig(config),
		mGrid(gameMap.mGrid),
		mBoundaries(gameMap.mBoundaries),
		mScreenCenter(Config::WINDOW_SIZE_Y / 2, Config::WINDOW_SIZE_X / 2)
	{
		Point pacmanCenter = Point(mScreenCenter.mRow - 50, mScreenCenter.mColumn);
		mPacman = std::make_unique<Pacman>(pacmanCenter, Point(0, 0), mConfig);
		mPacman->SetRadius(30.0f);
	}

	// IController
	void Setup() override {}
	void Update(double elapsedTime) override;
	void Draw() override;
	void KeyDown(Direction direction) override {}
	void UpdateGameState(GameState gameState) override;

	void UpdateScore(int score);

private:
	void DrawGameInitialCurtain();
	void DrawGameActiveCurtain();
	void DrawGamePausedCurtain();
	void DrawGameOverCurtain();
	void DrawHelpBoard();
	void DrawScore();


private:
	const Config& mConfig;
	GridPtr mGrid;
	Boundaries mBoundaries;
	PacmanPtr mPacman;
	Point mScreenCenter;
	GameState mGameState{ NOT_STARTED };
	int mScore{ 0 };
	Milliseconds mUpdateInterval{ 0ms };
	DurationSeconds mLastUpdate{ 0.0 };
};
typedef std::unique_ptr<GameCurtainController> GameCurtainPtr;

