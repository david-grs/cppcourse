#pragma once

#include <chrono>

#include "short_circular_buffer.hpp"

template<
	std::size_t _BufferSize,
	typename _Message,
	typename _MessageConsumer,
	typename _MessageDisposer,
	typename _Timestamp,
	typename _Timestamper,
	typename _TimestampThreshold,
	typename _Buffer = short_circular_buffer<_Timestamp, _BufferSize>
>
class message_throttler_interface
{
public:
	message_throttler_interface(
		const _MessageConsumer& messageConsumer, 
		const _MessageDisposer& messageDisposer, 
		const _Timestamper& timestamper,
		const _TimestampThreshold & timestampThreshold) :
		mMessageConsumer(messageConsumer),
		mMessageDisposer(messageDisposer),
		mTimestamper(timestamper),
		mTimestampThreshold(timestampThreshold)
	{ }

	message_throttler_interface(const message_throttler_interface&) = delete;
	message_throttler_interface& operator=(const message_throttler_interface&) = delete;

	message_throttler_interface& send(const _Message& message)
	{
		auto now = mTimestamper();

		try_make_space_in_buffer(now);
		try_send(message, now);

		return *this;
	}

private:
	void try_make_space_in_buffer(const _Timestamp& now)
	{
		if (mBuffer.full() && !mTimestampThreshold(now, mBuffer.front()))
			mBuffer.pop();
	}

	void try_send(const _Message& message, const _Timestamp& now)
	{
		if (mBuffer.full())
			dispose(message);
		else
			consume(message, now);
	}

	void consume(const _Message& message, const _Timestamp& now)
	{
		mMessageConsumer(message);
		mBuffer.push(now);
	}

	void dispose(const _Message& message)
	{
		mMessageDisposer(message);
	}

	_MessageConsumer mMessageConsumer;
	_MessageDisposer mMessageDisposer;

	_Timestamper mTimestamper;
	_TimestampThreshold mTimestampThreshold;

	_Buffer mBuffer;
};