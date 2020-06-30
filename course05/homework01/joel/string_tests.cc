#include "string.h"

#include <cassert>
#include <cstring>
#include <iostream>
#include <sstream>

void TestEmpty()
{
	String str;
	assert(str.Empty());
	assert(std::strcmp(str.c_str(), "") == 0);
}

void TestContents()
{
	char base[] = "this is a string";
	String str{base};
	assert(std::strcmp(str.c_str(), base) == 0);
}

void TestStream()
{
	std::stringstream stream;
	char base[] = "This is a string";
	String str{base};
	stream << str;
	assert(stream.str() == base);
}

void TestOperators()
{
	// few example strings
	String str1{"This is a string"};
	String str2{str1};
	String str3{"This is a different string"};
	// eq and ne
	assert(str1 == str2);
	assert(str1 != str3);

	// +
	String addedstr{str1 + str3};
	assert(addedstr.StartsWith(str1));
	// Missing letter at the start
	assert(!addedstr.StartsWith("his is a string"));
	// Extra letter at the start
	assert(!addedstr.StartsWith("TThis is a string"));
	// Extra letter at the end
	assert(!addedstr.StartsWith("This is a stringg"));
	assert(addedstr.EndsWith(str3));
	// extra letter at the end
	assert(!addedstr.EndsWith("This is a different stringg"));
	// missing letter at the end
	assert(!addedstr.EndsWith("This is a different strin"));
	// extra letter at the start
	assert(!addedstr.EndsWith("TThis is a different string"));

}

int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif

	TestEmpty();
	TestContents();
	TestStream();
	TestOperators();

	// TODO: other tests

	return 0;
}
