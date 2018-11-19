#pragma once

#include <string>

class GameStatus
{
public:
	enum class State
	{
		ReadyToStart,
		InProgress,
		Finished,
		GameOver
	};

	explicit GameStatus(int /*maxScore*/);

	State GetState() const { return mState; }
	void SetOver() { mState = GameStatus::State::GameOver; }
	bool IsInProgress() const { return GetState() == State::InProgress; }
	void OnAction();

	std::string GetScoreToDisplay() const;
	void IncreaseScore();
	bool Reset();
private:
	const int mMaxScore;
	int mScore{0};

	State mState{State::ReadyToStart};
};
