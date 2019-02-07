#include "message_throttler.hpp"

#include <functional>

template<typename _ClientId, std::size_t _BufferSize, typename _Message, typename _MessageConsumer, typename _MessageDisposer>
message_throttler<_ClientId, _BufferSize, _Message, _MessageConsumer, _MessageDisposer> make_message_throttler(_MessageConsumer messageConsumer, _MessageDisposer messageDisposer)
{
	return message_throttler<_ClientId, _BufferSize, _Message, _MessageConsumer, _MessageDisposer>(messageConsumer, messageDisposer);
}


int main()
{
	int last_message = 0;

	auto message_bus = make_message_throttler<std::size_t, 4, int>(
		[&last_message](int value) { last_message = value; },
		[](int) {}
	);

	message_bus.from(1).send(10);

	assert(last_message == 10);
	assert(last_message == 11);
}
