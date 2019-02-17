#include "throttler.h"

void Throttler::AddClient(const Client& client)
{
	auto config = client.GetConfig();
	mClientChannels.try_emplace(client.GetId(), SlidingWindow(config.mMessageLimit, config.mInterval));
}

bool Throttler::SendMessage(const Client::id_type& clientId, const std::string& msg)
{
	auto channel = mClientChannels.find(clientId);
	if (channel != mClientChannels.end())
	{
		return channel->second.SendMessage(msg);
	}
	return false;
}
