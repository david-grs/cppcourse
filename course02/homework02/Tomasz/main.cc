#include "message_throttler_commons.hpp"

#include <functional>
#include <iostream>

using Message = int;
using UserId = std::size_t;

void buffer_empty_test()
{
	short_circular_buffer<UserId, 4> buffer;

	assert(buffer.empty());
}

void buffer_full_test()
{
	short_circular_buffer<UserId, 4> buffer;

	buffer.push(1);
	buffer.push(2);
	buffer.push(3);
	buffer.push(4);

	assert(buffer.full());
	assert(buffer.front() == 1);
}

void throttler_test()
{
	Message last_consumed_message = 0;

	auto message_bus = make_message_throttler<UserId, 4, Message>(
		[&](const Message& message) { last_consumed_message = message; }
	);

	message_bus.from(1).send(1);
	message_bus.from(1).send(2);
	message_bus.from(1).send(3);

	assert(last_consumed_message == 3);
}

void throttler_dispose_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto message_bus = make_message_throttler<UserId, 4, Message>(
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	message_bus.from(1).send(1);
	message_bus.from(1).send(2);
	message_bus.from(1).send(3);
	message_bus.from(1).send(4);
	message_bus.from(1).send(5);
	message_bus.from(1).send(6);

	assert(last_consumed_message == 4);
	assert(last_disposed_message == 6);
}

int main()
{
	buffer_empty_test();
	buffer_full_test();
	//throttler_test();
	//throttler_dispose_test();
}
