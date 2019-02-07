#pragma once

#include <chrono>

#include "short_circular_buffer.hpp"

template<std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
class message_throttler_interface
{
public:
	message_throttler_interface(_MessageConsumer& messageConsumer, _MessageDisposer& messageDisposer);

	void send(const _Message& message);

private:
	void clear_buffer(std::size_t now);
	void update_buffer(std::size_t now);

	void consume(const _Message& message, std::size_t now);
	void dispose(const _Message& message);

	_MessageConsumer& mMessageConsumer;
	_MessageDisposer& mMessageDisposer;

	short_circular_buffer<std::size_t, _BufferSize> mBuffer;
};

template<std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer>::message_throttler_interface(_MessageConsumer& messageConsumer, _MessageDisposer& messageDisposer) :
	mMessageConsumer(messageConsumer),
	mMessageDisposer(messageDisposer)
{ }

template<std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
void message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer>::send(const _Message& message)
{
	std::size_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	clear_buffer(now);

	if (mBuffer.full())
		dispose(message);
	else
		consume(message, now);
}

template<std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
void message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer>::clear_buffer(std::size_t now)
{
	while (!mBuffer.empty() && mBuffer.front() < now)
		mBuffer.pop();
}

template<std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
void message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer>::update_buffer(std::size_t now)
{
	mBuffer.push(now);
}

template<std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
void message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer>::consume(const _Message& message, std::size_t now)
{
	mMessageConsumer(message);
	update_buffer(now);
}

template<std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
void message_throttler_interface<_BufferSize, _Message, _MessageConsumer, _MessageDisposer>::dispose(const _Message& message)
{
	mMessageDisposer(message);
}