#pragma once

#include <map>
#include <chrono>

#include "message_throttler.hpp"
#include "message_throttler_interface.hpp"

template<typename _Message>
struct message_swallower
{
	void operator()(const _Message& message)
	{ }
};

struct chrono_clock
{
	std::chrono::milliseconds operator()()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	}
};

template<
	typename _ClientId,
	typename _Message,
	typename _Clock = chrono_clock,
	typename _MessageConsumer = message_swallower<_Message>,
	typename _MessageDisposer = message_swallower<_Message>
>
message_throttler<_ClientId, _Message, _Clock, _MessageConsumer, _MessageDisposer> make_message_throttler(
	std::size_t bufferSize,
	decltype(_Clock{}() - _Clock{}()) threashold,
	_MessageConsumer messageConsumer = {},
	_MessageDisposer messageDisposer = {}
)
{
	return message_throttler<_ClientId, _Message, _Clock, _MessageConsumer, _MessageDisposer>(
		bufferSize,
		threashold,
		messageConsumer,
		messageDisposer);
}