#include "message_throttler_commons.hpp"

#include <functional>
#include <iostream>
#include <thread>

using Message = int;
using UserId = std::size_t;

void throttler_test()
{
	Message last_consumed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ 1000 },
		[&](const Message& message) { last_consumed_message = message; }
	);

	throttler.from(1).send(1);
	throttler.from(1).send(2);
	throttler.from(1).send(3);

	assert(last_consumed_message == 3);
}

void throttler_dispose_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ 1000 },
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	throttler.from(1).send(1);
	throttler.from(1).send(2);
	throttler.from(1).send(3);
	throttler.from(1).send(4);
	throttler.from(1).send(5);
	throttler.from(1).send(6);

	assert(last_consumed_message == 4);
	assert(last_disposed_message == 6);
}

void throttler_single_interface_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ 1000 },
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	throttler.from(1)
		.send(1)
		.send(2)
		.send(3)
		.send(4)
		.send(5)
		.send(6);

	assert(last_consumed_message == 4);
	assert(last_disposed_message == 6);
}

void throttler_multiple_users_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ 1000 },
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	throttler.from(1).send(1);
	throttler.from(1).send(2);
	throttler.from(1).send(3);
	throttler.from(1).send(4);
	throttler.from(1).send(5);
	throttler.from(2).send(7);
	throttler.from(2).send(8);

	assert(last_consumed_message == 8);
	assert(last_disposed_message == 5);
}

void throttler_timeout_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ -1 },
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	throttler.from(1).send(1);
	throttler.from(1).send(2);
	throttler.from(1).send(3);
	throttler.from(1).send(4);
	throttler.from(1).send(5);
	throttler.from(1).send(6);

	assert(last_consumed_message == 6);
	assert(last_disposed_message == 0);
}

void throttler_chrono_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ 100 },
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	throttler.from(1).send(1);
	throttler.from(1).send(2);
	throttler.from(1).send(3);
	throttler.from(1).send(4);
	throttler.from(1).send(5);

	std::this_thread::sleep_for(std::chrono::milliseconds{ 50 });

	throttler.from(1).send(6);
	throttler.from(1).send(7);

	std::this_thread::sleep_for(std::chrono::milliseconds{ 50 });

	throttler.from(1).send(8);
	throttler.from(1).send(9);

	assert(last_consumed_message == 9);
	assert(last_disposed_message == 7);
}

void throttler_chrono_partial_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ 100 },
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	throttler.from(1).send(1);
	throttler.from(1).send(2);

	std::this_thread::sleep_for(std::chrono::milliseconds{ 50 });

	throttler.from(1).send(3);
	throttler.from(1).send(4);

	std::this_thread::sleep_for(std::chrono::milliseconds{ 50 });

	throttler.from(1).send(5);
	throttler.from(1).send(6);
	throttler.from(1).send(7);

	assert(last_consumed_message == 6);
	assert(last_disposed_message == 7);
}

void throttler_chrono_full_cycle_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ 100 },
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	throttler.from(1).send(1);
	throttler.from(1).send(2);
	throttler.from(1).send(3);
	throttler.from(1).send(4);

	std::this_thread::sleep_for(std::chrono::milliseconds{ 100 });

	throttler.from(1).send(5);
	throttler.from(1).send(6);
	throttler.from(1).send(7);
	throttler.from(1).send(8);
	throttler.from(1).send(9);

	assert(last_consumed_message == 8);
	assert(last_disposed_message == 9);
}

void throttler_chrono_muliple_users_test()
{
	Message last_consumed_message = 0;
	Message last_disposed_message = 0;

	auto throttler = make_message_throttler<UserId, Message>(
		4,
		std::chrono::milliseconds{ 100 },
		[&](const Message& message) { last_consumed_message = message; },
		[&](const Message& message) { last_disposed_message = message; }
	);

	throttler.from(1).send(1);
	throttler.from(1).send(2);
	throttler.from(2).send(3);
	throttler.from(2).send(4);

	std::this_thread::sleep_for(std::chrono::milliseconds{ 50 });

	throttler.from(1).send(5);
	throttler.from(1).send(6);
	throttler.from(1).send(7);
	throttler.from(1).send(8);
	throttler.from(2).send(9);

	assert(last_consumed_message == 9);
	assert(last_disposed_message == 8);
}

int main()
{
	throttler_test();
	throttler_dispose_test();
	throttler_single_interface_test();
	throttler_multiple_users_test();
	throttler_timeout_test();
	throttler_chrono_test();
	throttler_chrono_partial_test();
	throttler_chrono_full_cycle_test();
	throttler_chrono_muliple_users_test();
}
