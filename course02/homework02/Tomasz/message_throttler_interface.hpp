#pragma once

#include <boost/circular_buffer.hpp>

template<
	typename _Message,
	typename _Clock,
	typename _MessageConsumer,
	typename _MessageDisposer
>
class message_throttler_interface
{
private:
	using _Time = decltype(_Clock{}());
	using _Duration = decltype(_Clock{}() - _Clock{}());

public:
	message_throttler_interface(
		std::size_t bufferSize,
		_Duration threashold,
		_MessageConsumer& messageConsumer,
		_MessageDisposer& messageDisposer) :
		mBuffer(bufferSize),
		mThreashold(threashold),
		mMessageConsumer(messageConsumer),
		mMessageDisposer(messageDisposer)
	{ }

	message_throttler_interface(const message_throttler_interface&) = delete;
	message_throttler_interface& operator=(const message_throttler_interface&) = delete;

	message_throttler_interface& send(const _Message& message)
	{
		auto now = mClock();

		try_make_space_in_buffer(now);
		try_send(message, now);

		return *this;
	}

private:
	void try_make_space_in_buffer(const _Time& now)
	{
		if (mBuffer.full() && mThreashold < now - mBuffer.front())
			mBuffer.pop_front();
	}

	void try_send(const _Message& message, const _Time& now)
	{
		if (mBuffer.full())
			dispose(message);
		else
			consume(message, now);
	}

	void consume(const _Message& message, const _Time& now)
	{
		mMessageConsumer(message);
		mBuffer.push_back(now);
	}

	void dispose(const _Message& message)
	{
		mMessageDisposer(message);
	}

	_Clock mClock;
	_Duration mThreashold;

	_MessageConsumer& mMessageConsumer;
	_MessageDisposer& mMessageDisposer;

	boost::circular_buffer<_Time> mBuffer;
};