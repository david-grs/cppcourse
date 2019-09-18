#pragma once

#include <deque>
#include <chrono>
#include <vector>
#include <stdexcept>

struct WindowConfig
{
	std::chrono::seconds mDuration = std::chrono::seconds(10);
	int mMaxNumMessages = 5;
};

template<class Message>
struct TimestampedMessage
{
	std::chrono::time_point<std::chrono::steady_clock> mTimestamp;
	Message mMessage;
};

template<class Message>
class Buffer
{
public:
	using value_type = Message;

	Buffer(const WindowConfig& conf);
	void TryToAddMessage(const Message& message);
	std::vector<Message> DumpMessages() const;

private:
	bool CanAddMessage(std::chrono::time_point<std::chrono::steady_clock> currentTime) const;

	WindowConfig mWindowConfig;
	std::deque<TimestampedMessage<Message> > mTimestampedMessages;
};

template<class Message>
Buffer<Message>::Buffer(const WindowConfig& conf) :
		mWindowConfig(conf)
{
	if (conf.mMaxNumMessages <= 0)
		throw std::runtime_error("Invalid configuration: max number of messages per time window must be positive!");
}

template<class Message>
bool Buffer<Message>::CanAddMessage(std::chrono::time_point<std::chrono::steady_clock> currentTime) const
{
	if (mTimestampedMessages.size() >= mWindowConfig.mMaxNumMessages)
	{
		auto timestampAtStartOfWindow = mTimestampedMessages[
				mTimestampedMessages.size()	- mWindowConfig.mMaxNumMessages].mTimestamp;
		return (timestampAtStartOfWindow < currentTime - mWindowConfig.mDuration);
	}
	return true;
}

template<class Message>
void Buffer<Message>::TryToAddMessage(const Message& message)
{
	auto currentTime = std::chrono::steady_clock::now();
	if (CanAddMessage(currentTime))
	{
		TimestampedMessage<Message> tsMsg;
		tsMsg.mMessage = message;
		tsMsg.mTimestamp = currentTime;
		mTimestampedMessages.push_back(tsMsg);
	}
}

template<class Message>
std::vector<Message> Buffer<Message>::DumpMessages() const
{
	std::vector<Message> result;
	for (auto tsMsg : mTimestampedMessages)
		result.push_back(tsMsg.mMessage);

	return result;
}
