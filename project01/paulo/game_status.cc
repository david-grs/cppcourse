#include "game_status.h"

#include <sstream>

GameStatus::GameStatus(int maxScore) :
	mMaxScore(maxScore),
	mScore(0)
{}

std::string GameStatus::GetScoreToDisplay() const
{
	std::ostringstream oss;
	oss << "Score: " << mScore;
	return oss.str();
}

void GameStatus::OnAction()
{
	if (mState == State::ReadyToStart)
	{
		mState = State::InProgress;
	}
}

void GameStatus::IncreaseScore()
{
	++mScore;
	if (mScore == mMaxScore)
	{
		mState = GameStatus::State::Finished;
	}
}

bool GameStatus::Reset()
{
	if (mState == State::GameOver || mState == State::Finished)
	{
		mScore = 0;
		mState = State::ReadyToStart;
		return true;
	}
	return false;
}
