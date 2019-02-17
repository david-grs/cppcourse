#pragma once

#include "sliding_window.h"
#include <map>

struct Client
{
	
	struct Config
	{
		Config(int messageLimit, int interval)
			:
			mMessageLimit(messageLimit),
			mInterval(interval)
		{
		}

		int mMessageLimit;
		int mInterval;
	};

	typedef int id_type;

	Client(int id, const Config& config)
		:
		mId(id),
		mConfig(config)
	{
	}

	const int& GetId() const { return mId; }
	const Config& GetConfig() const { return mConfig; }

private:
	const id_type mId;
	const Config& mConfig;
};

class Throttler
{
public:

	void AddClient(const Client& client);
	bool SendMessage(const Client::id_type& clientId, const std::string& msg);

private:
	std::map<Client::id_type, SlidingWindow> mClientChannels;
};

