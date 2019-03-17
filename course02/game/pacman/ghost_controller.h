#pragma once

#include "types.h"
#include "ghost.h"

typedef std::unique_ptr<Ghost> GhostPtr;

class GhostController : public IController
{
public:
	GhostController(const Config& config, GhostPtr& ghost, GameMap& gameMap)
		:
		mConfig(config),
		mGhost(std::move(ghost)),
		mGrid(gameMap.mGrid),
		mBoundaries(gameMap.mBoundaries)
	{
	}

	// IController
	void Setup() override {};
	void Update(double delta) override;
	void Draw() override;
	void KeyDown(Direction direction) override {};
	void UpdateGameState(GameState gameState) override { mGameState = gameState;  }

	const Point& GetObjectPosition() const { return mGhost->GetGridPosition();  }

private:
	bool GhostAllowedToEnterNextField(Direction direction, GameField* nextField);
	bool GhostCanMoveInItsOwnField();
	GameField* GetNextField(Direction direction);
	bool GhostIsInNextField(GameField* nextField);
	Direction GetRandomDirection();

private:
	
	const Config& mConfig;
	GhostPtr mGhost;
	GridPtr mGrid;
	Boundaries mBoundaries;
	GameState mGameState{ NOT_STARTED };
	Milliseconds mUpdateInterval{ 0ms };
	DurationSeconds mLastUpdate{ 0.0 };
};
typedef std::unique_ptr<GhostController> GhostControllerPtr;
typedef std::vector<GhostControllerPtr> GhostControllers;
