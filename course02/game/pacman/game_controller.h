#pragma once

#include "config.h"
#include "types.h"
#include "empty_field.h"
#include "wall_field.h"
#include "temporary_wall.h"
#include "basic_field.h"
#include "coin_field.h"
#include "pacman_controller.h"
#include "ghost_controller.h"
#include "game_curtain_controller.h"

using namespace ci;

struct GameWorld
{
	GameMap mGameMap;
	std::vector<GhostPtr> mGhosts;
	PacmanPtr mPacman;
};

class GameController : public IController
{
public:
	GameController(const Config& config)
		:
		mConfig(config)
	{
	}

	void Setup() override;
	void Update(double elapsedTime) override;
	void Draw() override;

	void KeyDown(Direction direction) override;
	void UpdateGameState(GameState gameState) override;
	void UpdateScore(int score) { mCurtainController->UpdateScore(score); }

private:
	GameWorld CreateGameWorld();
	void SetupControllers(GameWorld& gameWorld);
	Boundaries GetBoundaries(const Grid& grid);
	void ReleaseGhosts();
	bool IsGameOver();

private:
	const Config& mConfig;
	GameWorld mGameWorld;
	GameState mGameState{ NOT_STARTED };
	PacmanControllerPtr mPacmanController;
	GhostControllers mGhostControllers;
	GameCurtainPtr mCurtainController;
	double mTimeSinceLastUpdate = 0.0;
	DurationSeconds mTimeSinceGameActive{ 0.0 };
	bool mGhostsReleased{ false };
};
typedef std::unique_ptr<GameController> GameControllerPtr;
		
