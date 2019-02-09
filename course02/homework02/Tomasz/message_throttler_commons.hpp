#pragma once

#include "message_throttler.hpp"

#include <chrono>

template<typename _Message>
class message_swallower
{
public:
	void operator()(const _Message& message)
	{ }
};

class chrono_timestamp_threshold
{
public:
	chrono_timestamp_threshold(std::chrono::milliseconds milliseconds) :
		milliseconds(milliseconds)
	{ }

	bool operator()(std::chrono::milliseconds now, std::chrono::milliseconds last)
	{
		return (now - last) < milliseconds;
	}

private:
	std::chrono::milliseconds milliseconds;
};

class chrono_timestamper
{
public:
	std::chrono::milliseconds operator()()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	}
};

template<
	typename _ClientId,
	std::size_t _BufferSize,
	typename _Message,
	typename _Timestamp = std::chrono::milliseconds,
	typename _MessageConsumer = message_swallower<_Message>,
	typename _MessageDisposer = message_swallower<_Message>,
	typename _Timestamper = chrono_timestamper,
	typename _TimestampThreshold = chrono_timestamp_threshold
>
message_throttler<_ClientId, _BufferSize, _Message, _MessageConsumer, _MessageDisposer, _Timestamp, _Timestamper, _TimestampThreshold> make_message_throttler(
	_MessageConsumer messageConsumer = {},
	_MessageDisposer messageDisposer = {},
	_TimestampThreshold timestampThreshold = { std::chrono::milliseconds {1000} },
	_Timestamper timestamper = {}
)
{
	return message_throttler<_ClientId, _BufferSize, _Message, _MessageConsumer, _MessageDisposer, _Timestamp, _Timestamper, _TimestampThreshold>(
		messageConsumer,
		messageDisposer,
		timestamper,
		timestampThreshold);
}