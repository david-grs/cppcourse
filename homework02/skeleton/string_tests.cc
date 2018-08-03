#include "string.h"

#include <iostream>
#include <cassert>

int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

	String s1;
	assert(s1.empty());

	String s2 = "foobar";
	std::cout << s2 << std::endl;

	s2[0] = 'g';
	assert(s2 == "goobar");

	const String s3 = "hello " + s2;
	assert(s3.size() == 12);
	assert(s3.capacity() >= 12);

	const char* raw = s3.c_str();
	assert(raw == String("hello goobar"));

	assert(s3[0] == 'h');

	std::string s4 = s3;
	assert(s4 == s3);
}
