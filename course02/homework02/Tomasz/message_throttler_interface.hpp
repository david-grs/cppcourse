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
	typename _TimestampValidator,
	typename _Buffer = short_circular_buffer<_Timestamp, _BufferSize>
>
class message_throttler_interface
{
public:
	message_throttler_interface(
		const _MessageConsumer& messageConsumer, 
		const _MessageDisposer& messageDisposer, 
		const _Timestamper& timestamper,
		const _TimestampValidator& timestampValidator) :
		mMessageConsumer(messageConsumer),
		mMessageDisposer(messageDisposer),
		mTimestamper(timestamper),
		mTimestampValidator(timestampValidator)
	{ }

	message_throttler_interface& send(const _Message& message)
	{
		auto now = _Timestamper{}();

		try_make_space_in_buffer(now);
		try_send(message, now);

		return *this;
	}

private:
	void try_make_space_in_buffer(const _Timestamp& now)
	{
		if (mBuffer.full() && !mTimestampValidator(now, mBuffer.front()))
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
	_TimestampValidator mTimestampValidator;

	_Buffer mBuffer;
};