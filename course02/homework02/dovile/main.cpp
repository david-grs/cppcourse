#include "throttler.h"

#include <thread>
#include <cassert>

using namespace std::chrono_literals;
using namespace std::this_thread;


void test_message_rejected()
{
	Throttler throttler;
	int messageLimit = 2;
	int intervalInSeconds = 1;
	throttler.AddClient(Client(1, Client::Config(messageLimit, intervalInSeconds)));

	std::string msg = "the message";

	assert(throttler.SendMessage(1, msg));
	sleep_for(50ms);
	assert(throttler.SendMessage(1, msg));
	sleep_for(50ms);
	assert(!throttler.SendMessage(1, msg));  
}

void test_messegae_rejected_and_later_accepted()
{
	Throttler throttler;
	int messageLimit = 2;
	int intervalInSeconds = 1;
	throttler.AddClient(Client(1, Client::Config(messageLimit, intervalInSeconds)));

	std::string msg = "message";

	assert(throttler.SendMessage(1, msg));
	sleep_for(50ms);
	assert(throttler.SendMessage(1, msg));
	sleep_for(50ms);
	assert(!throttler.SendMessage(1, msg));
	sleep_for(1s);
	assert(throttler.SendMessage(1, msg));
}

void test_all_messages_accepted()
{
	Throttler throttler;
	int messageLimit = 2;
	int intervalInSeconds = 1;
	throttler.AddClient(Client(1, Client::Config(messageLimit, intervalInSeconds)));

	std::string msg = "message";

	assert(throttler.SendMessage(1, msg));
	sleep_for(500ms);
	assert(throttler.SendMessage(1, msg));
	sleep_for(500ms);
	assert(throttler.SendMessage(1, msg));
	sleep_for(500ms);
	assert(throttler.SendMessage(1, msg));
}

int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif
	test_message_rejected();
	test_messegae_rejected_and_later_accepted();
	test_all_messages_accepted();
	return 0;
}