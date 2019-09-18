#include "SlidingWindow.h"
#include "Buffer.h"

#include <assert.h>

void TestDroppedLastMessage()
{
	WindowConfig conf;
	auto slidingWindow = SlidingWindow<int>(conf);
	for (int i = 1; i < 7; ++i)
		slidingWindow.Send(1, i);

	auto messageDump = slidingWindow.DumpMessages(1);
	assert(messageDump.size() == 5);
	int i = 1;
	for (auto msg : messageDump)
	{
		assert(msg == i);
		++i;
	}
}

void TestMultipleClients()
{
	WindowConfig conf;
	conf.mMaxNumMessages = 8;
	auto slidingWindow = SlidingWindow<int>(conf);
	for (int i = 1; i < 7; ++i)
		slidingWindow.Send(1, i);

	for (int i = 1; i < 15; ++i)
		slidingWindow.Send(2, i);

	auto messageDump = slidingWindow.DumpMessages(1);
	assert(messageDump.size() == 6);
	int i = 1;
	for (auto msg : messageDump)
	{
		assert(msg == i);
		++i;
	}

	messageDump = slidingWindow.DumpMessages(2);
	assert(messageDump.size() == 8);
	i = 1;
	for (auto msg : messageDump)
	{
		assert(msg == i);
		++i;
	}
}

void TestDumpQuietClient()
{
	WindowConfig conf;
	auto slidingWindow = SlidingWindow<int>(conf);
	auto dump = slidingWindow.DumpMessages(1);
	assert(dump.size() == 0);
}

void TestNegativeNumMessagesInWindowConf()
{
	WindowConfig conf;
	conf.mMaxNumMessages = -5;
	bool failed = true;
	try
	{
		auto slidingWindow = SlidingWindow<int>(conf);
	}
	catch (std::exception e)
	{
		failed = false;
	}
	assert(!failed);
}

int main()
{
	TestDroppedLastMessage();
	TestMultipleClients();
	TestDumpQuietClient();
	TestNegativeNumMessagesInWindowConf();
	return 0;
}
