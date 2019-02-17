#pragma once

#include <chrono>
#include <deque>
#include <string>

class SlidingWindow
{
	typedef std::chrono::seconds seconds;
	typedef std::chrono::steady_clock SteadyClock;

public:
	SlidingWindow(int messageLimit, int intervalInSeconds)
		:
		mMessageLimit(messageLimit),
		mInterval(seconds(intervalInSeconds))
	{
	}

	bool SendMessage(const std::string& message);
	
private:
	int mMessageLimit;
	seconds mInterval;
	std::deque<SteadyClock::time_point> mWindow;
};