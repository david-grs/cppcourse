#include "string.h"
#include <iostream>
#include <cassert>

void TestEmpty()
{
	String str;
	assert(str.Empty());
}

void TestSize()
{
	String str{ "test" };
	assert(str.Size() == 4);
}

void TestEqual()
{
	String str1{ "test" };
	String str2{ "test" };
	assert(str1 == str2);
}


void TestUnequal()
{
	String str1{ "This is not equal" };
	String str2{ "to this" };
	assert(str1 != str2);
}


void TestStartSubstring()
{
	String str{ "Test Substring" };
	String substr{ "Substring" };
	assert(str.Substring(5) == substr);
}


void TestStartEndSubstring()
{
	String str{ "Test Substring with End" };
	String substr{ "Substring" };
	assert(str.Substring(5,9) == substr);
}


int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif
	std::cout << "Running!" << std::endl;
	TestEmpty();
	TestSize();
	TestEqual();
	TestUnequal();
	TestStartSubstring();
	TestStartEndSubstring();
	std::cout << "Done!" << std::endl;
	return 0;
}
