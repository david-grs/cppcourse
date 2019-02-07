#include "message_throttler.hpp"

#include <functional>


int main()
{
	int last_consumed_message = 0;
	int last_disposed_message = 0;

	auto message_bus = make_message_throttler<std::size_t, 4, int>(
		[&last_consumed_message](int value) { last_consumed_message = value; },
		[&last_disposed_message](int value) { last_disposed_message = value; }
	);

	message_bus.from(1).send(10);

	assert(last_consumed_message == 10);
	assert(last_disposed_message == 0);
}
