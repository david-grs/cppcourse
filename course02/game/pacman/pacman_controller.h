#pragma once

#include "types.h"
#include "pacman.h"

class PacmanController : public IController
{
public:
	PacmanController(const Config& config, PacmanPtr& pacman, GameMap& gameMap)
		:
		mConfig(config),
		mPacman(std::move(pacman)),
		mGrid(gameMap.mGrid),
		mBoundaries(gameMap.mBoundaries)
	{
	}

	// IController
	void Setup() override {};
	void Update(double delta) override;
	void Draw() override;
	void KeyDown(Direction direction) override;
	void UpdateGameState(GameState gameState) override { mGameState = gameState; }

	const Point& GetObjectPosition() const { return mPacman->GetGridPosition(); }
	void SetScoreUpdateCallback(std::function<void(int)> callBack) { mUpdateScore = callBack; }

private:
	bool PacmanAllowedToEnterNextField(Direction direction, GameField* nextField);
	bool PacmanCanMoveInItsOwnField();
	GameField* GetNextField(Direction direction);
	bool PacmanIsInNextField(GameField* nextField);

private:
	const Config& mConfig;
	PacmanPtr mPacman;
	GridPtr mGrid;
	Boundaries mBoundaries;
	GameState mGameState{ NOT_STARTED };
	Milliseconds mUpdateInterval{ 0ms };
	DurationSeconds mLastUpdate{ 0.0 };
	std::function<void(int score)> mUpdateScore;
};
typedef std::unique_ptr<PacmanController> PacmanControllerPtr;