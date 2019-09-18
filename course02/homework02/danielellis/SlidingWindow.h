#pragma once

#include <map>
#include <queue>
#include <chrono>
#include <vector>

#include "Buffer.h"

template<class Message>
class SlidingWindow
{
public:
	using value_type = Message;

	SlidingWindow(const WindowConfig& conf);
	void Send(int clientId, const Message& message);
	std::vector<Message> DumpMessages(int clientId) const;

private:
	WindowConfig mWindowConfig;
	std::map<int, Buffer<Message> > mClientBuffers;
};

template<class Message>
SlidingWindow<Message>::SlidingWindow(const WindowConfig& conf) :
		mWindowConfig(conf)
{
	if (conf.mMaxNumMessages <= 0)
		throw std::runtime_error("Invalid configuration: max number of messages per time window must be positive!");
}

template<class Message>
void SlidingWindow<Message>::Send(int clientId, const Message& message)
{
	if (mClientBuffers.count(clientId) == 0)
		mClientBuffers.insert(std::pair<int, Buffer<Message> >(clientId, Buffer<Message>(mWindowConfig)));

	Buffer<Message>& buffer = mClientBuffers.at(clientId);
	buffer.TryToAddMessage(message);
}

template<class Message>
std::vector<Message> SlidingWindow<Message>::DumpMessages(int clientId) const
{
	auto buffer = mClientBuffers.find(clientId);
	if (buffer != mClientBuffers.end())
		return buffer->second.DumpMessages();
	else
		return std::vector<Message>();
}
