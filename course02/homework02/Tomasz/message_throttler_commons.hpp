#pragma once

#include <map>
#include <chrono>

#include "short_circular_buffer.hpp"
#include "message_throttler.hpp"
#include "message_throttler_interface.hpp"

template<typename _Message>
struct message_swallower
{
	void operator()(const _Message& message)
	{ }
};

struct chrono_timestamp_threshold
{
	chrono_timestamp_threshold(std::chrono::milliseconds milliseconds) :
		milliseconds(milliseconds)
	{ }

	bool operator()(std::chrono::milliseconds now, std::chrono::milliseconds timestamp)
	{
		return (now - timestamp) < milliseconds;
	}

	std::chrono::milliseconds milliseconds;
};

struct chrono_timestamper
{
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
	typename _TimestampThreshold = chrono_timestamp_threshold,
	typename _Buffer = short_circular_buffer<_Timestamp, _BufferSize>,
	typename _MessageThrottlerInterface = message_throttler_interface<_Message, _MessageConsumer, _MessageDisposer, _Timestamp, _Timestamper, _TimestampThreshold, _Buffer>,
	typename _Map = std::map<_ClientId, std::unique_ptr<_MessageThrottlerInterface>>
>
message_throttler<_ClientId, _Message, _MessageConsumer, _MessageDisposer, _Timestamp, _Timestamper, _TimestampThreshold, _MessageThrottlerInterface, _Map> make_message_throttler(
	_MessageConsumer messageConsumer = {},
	_MessageDisposer messageDisposer = {},
	_TimestampThreshold timestampThreshold = { std::chrono::milliseconds {1000} },
	_Timestamper timestamper = {}
)
{
	return message_throttler<_ClientId, _Message, _MessageConsumer, _MessageDisposer, _Timestamp, _Timestamper, _TimestampThreshold, _MessageThrottlerInterface, _Map>(
		messageConsumer,
		messageDisposer,
		timestamper,
		timestampThreshold);
}