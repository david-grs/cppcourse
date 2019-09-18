#include "throttle.cc"
#include <iostream>
#include <sstream>
#include <thread>

int main()
{
	Throttle throttle;

	UserID id = 5;

	int i = 0;
	for(; i<=20; i++)
	{
		std::ostringstream stringStream;
		stringStream << "Hello " << i;
		throttle.SendMessage(id, stringStream.str());
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));

	for(; i<=40; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		std::ostringstream stringStream;
		stringStream << "Hello " << i;
		throttle.SendMessage(id, stringStream.str());
	}
}
