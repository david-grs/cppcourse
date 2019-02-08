#include "message_throttler_commons.hpp"

#include <functional>

using Message = int;
using UserId = std::size_t;

void basic_test()
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

void dispose_test()
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
	assert(last_consumed_message == 6);
}

int main()
{
	basic_test();
	dispose_test();
}
