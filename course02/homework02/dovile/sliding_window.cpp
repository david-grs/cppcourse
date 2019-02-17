#include "sliding_window.h"
#include <algorithm>

bool SlidingWindow::SendMessage(const std::string& message)
{
	auto now = SteadyClock::now();

	if (mWindow.size() <  mMessageLimit)
	{
		mWindow.emplace_back(now);
		return true;
	}
	else
	{
		bool canSend = std::any_of(mWindow.begin(), mWindow.end(), [&](SteadyClock::time_point sentTime)
		{
			return ((now - sentTime) > mInterval);
		});

		if (canSend)
		{
			mWindow.emplace_back(now);

			if (mWindow.size() > mMessageLimit)
			{
				mWindow.pop_front();
			}

			return true;
		}

		return false;
	}
}