#include "string.h"

#include <cassert>

void TestEmpty()
{
    String str;
	assert(str.Empty());
}

void TestSetString()
{
    String str;
    str.SetString("this is my string");
    assert(str.GetString() == "this is my string");
}

int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif

	TestEmpty();

    TestSetString();

	return 0;
}

