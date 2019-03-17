#include "game_curtain_controller.h"
#include "pacman_controller.h"
#include <cinder/Text.h>
#include <boost/lexical_cast.hpp>

void GameCurtainController::UpdateGameState(GameState gameState)
{
	if (mGameState != OVER)
	{
		mGameState = gameState;
	}
}

void GameCurtainController::Update(double elapsedTime)
{
	auto updateNow = std::chrono::duration<double>(elapsedTime);
	auto timeDelta = updateNow - mLastUpdate;
	mUpdateInterval += std::chrono::duration_cast<std::chrono::milliseconds>(timeDelta);

	if (mGameState != ACTIVE && mUpdateInterval >= mConfig.CURTAIN_UPDATE_INTERVAL)
	{
		mPacman->UpdateMouth(timeDelta.count());
	}

	mLastUpdate = updateNow;
}

void GameCurtainController::Draw()
{
	
	if (mGameState == NOT_STARTED)
	{
		DrawGameInitialCurtain();
	}
	else if (mGameState == ACTIVE)
	{
		DrawGameActiveCurtain();
	}
	else if (mGameState == PAUSED)
	{
		DrawGamePausedCurtain();
	}
	else if (mGameState == OVER)
	{
		DrawGameOverCurtain();
	}
}

void GameCurtainController::DrawGameInitialCurtain()
{
	mPacman->Draw();

	ci::gl::color(mConfig.BLUE);
	ci::gl::Texture2dRef texture;
	ci::TextLayout startText;
	startText.setFont(ci::Font("Arial", 35));
	startText.setColor(mConfig.BLUE);
	startText.addLine("Press SPACE to start game");
	texture = ci::gl::Texture2d::create(startText.render(true, false));
	int colOffset = texture->getWidth() / 2;
	ci::gl::draw(texture, ci::vec2(mScreenCenter.mColumn - colOffset, mScreenCenter.mRow ));
}

void GameCurtainController::DrawGameActiveCurtain()
{
	for (auto& row : *mGrid)
	{
		for (auto& field : row)
		{
			field->Draw();
		}
	}

	DrawScore();
	DrawHelpBoard();
}

void GameCurtainController::DrawGamePausedCurtain()
{
	mPacman->Draw();

	ci::gl::color(mConfig.BLUE);
	ci::gl::Texture2dRef texture;
	ci::TextLayout text;
	text.setFont(ci::Font("Arial", 35));
	text.setColor(mConfig.BLUE);
	text.addCenteredLine("Game is paused");
	text.addCenteredLine("Press SPACE to continue");
	texture = ci::gl::Texture2d::create(text.render(true, false));
	int colOffset = texture->getWidth() / 2;
	ci::gl::draw(texture, ci::vec2(mScreenCenter.mColumn - colOffset, mScreenCenter.mRow));
}

void GameCurtainController::DrawGameOverCurtain()
{
	ci::gl::color(mConfig.RED);
	ci::gl::Texture2dRef texture;
	ci::TextLayout text;
	text.setFont(ci::Font("Arial", 35));
	text.setColor(mConfig.RED);
	text.addCenteredLine("GAME OVER");
	text.addCenteredLine("FINAL SCORE: " + boost::lexical_cast<std::string>(mScore));
	texture = ci::gl::Texture2d::create(text.render(true, false));
	int colOffset = texture->getWidth() / 2;
	int rowOffset = texture->getHeight() / 2;
	ci::gl::draw(texture, ci::vec2(mScreenCenter.mColumn - colOffset, mScreenCenter.mRow - rowOffset));
}

void GameCurtainController::DrawHelpBoard()
{
	ci::gl::color(mConfig.YELLOW);

	ci::TextLayout text;
	ci::gl::Texture2dRef texture;
	text.setFont(ci::Font("Arial", 20));
	text.setColor(mConfig.YELLOW);
	text.addLine("press [ESC] to pause");
	texture = ci::gl::Texture2d::create(text.render(true, false));
	auto columnOffset = texture->getWidth();
	ci::gl::draw(texture, ci::vec2(mBoundaries.mMapPixelsMax.mColumn - columnOffset, mBoundaries.mMapPixelsMax.mRow + 5));
}

void GameCurtainController::UpdateScore(int score)
{
	mScore += score;
}

void GameCurtainController::DrawScore()
{
	ci::gl::color(mConfig.RED);

	ci::TextLayout text;
	ci::gl::Texture2dRef texture;
	text.setFont(ci::Font("Arial", 28));
	text.setColor(mConfig.RED);
	text.addLine("Score: " + boost::lexical_cast<std::string>(mScore));
	texture = ci::gl::Texture2d::create(text.render(true, false));
	ci::gl::draw(texture, ci::vec2(mBoundaries.mMapPixelsMin.mColumn, mBoundaries.mMapPixelsMax.mRow + 5));
}