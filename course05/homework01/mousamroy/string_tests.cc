#include "string.h"

#include <cassert>
#include <iostream>

void TestEmpty()
{
	String str;
	assert(str.Empty());
}

void TestNonEmpty()
{
	String str(std::string("this is a non-empty string"));
	assert(!str.Empty());
}

void TestZeroSize()
{
	String str;
	assert(str.Size() == 0);
}

void TestNonZeroSize()
{
	std::string testStr("this is another non-empty string");
	String str(testStr);
	assert(str.Size() == testStr.size());
}

void TestStreamOperator()
{
	String str("this string should be printed on screen");
	std::cout << str;
}
// TODO add more tests
// TODO test constructor throws

int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif

	TestEmpty();
	TestNonEmpty();
	TestZeroSize();
	TestNonZeroSize();
	TestStreamOperator();

	return 0;
}
