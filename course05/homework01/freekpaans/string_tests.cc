#include "string.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

void TestEmpty()
{
	String str;
	assert(str.Empty());
}

void test_default_ctor_string_has_zero_size()
{
	String str;
	assert(str.Size() == 0);
}


void test_default_ctor_strings_are_equal()
{
	String str1;
	String str2;

	assert(str1 == str2);
}

void test_default_ctor_strings_are_not_unequal()
{
	String str1;
	String str2;

	assert(!(str1 != str2));
}

void test_equal_strings_are_equal()
{
	String str1{"hello"};
	String str2{"hello"};

	assert(str1 == str2);
}


void test_unequal_strings_are_unequal()
{
	String str1{"hello"};
	String str2{"world"};

	assert(str1 != str2);
}

void test_strings_with_same_prefix_are_unequal()
{
	String str1{"hello"};
	String str2{"hello, world"};

	assert(str1 != str2);
}

void test_non_empty_string_has_correct_size()
{
	String str{"hello"};

	assert(str.Size() == 5);
}

void test_non_empty_string_is_not_empty()
{
	String str{"hello"};

	assert(!str.Empty());
}

void test_to_ostream_outputs_correct_value()
{
	std::ostringstream os;

	String str{"hello world"};

	os << str;

	assert(os.str() == "hello world");
}

void test_from_istream_gets_correct_value()
{
	std::istringstream is {"hello, istream"};

	String str = StringFromIstream(is);

	assert(str == String{"hello,"});
}


void test_substring_start()
{
	String str{"a test"};

	assert(str.Substring(2) == String{"test"});
}

void test_substring_start_and_end()
{
	String str{"a test"};

	assert(str.Substring(1, 3) == String{" te"});
}

void test_max_size_throws_assertion() {

	std::string x;
	for(int i=0; i<String::MaxChars+1; i++)
	{
		x+="x";
	}

	try
	{
		String str{x};
		std::cerr << "Should have thrown runtime_error" << std::endl;
		assert(false);
	}
	catch(std::runtime_error)
	{
	}
}


int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif

	TestEmpty();
	test_default_ctor_string_has_zero_size();
	test_default_ctor_strings_are_equal();
	test_default_ctor_strings_are_not_unequal();
	test_equal_strings_are_equal();
	test_unequal_strings_are_unequal();
	test_strings_with_same_prefix_are_unequal();
	test_non_empty_string_has_correct_size();
	test_non_empty_string_is_not_empty();
	test_to_ostream_outputs_correct_value();
	test_from_istream_gets_correct_value();
	test_substring_start();
	test_substring_start_and_end();
	test_max_size_throws_assertion();

	std::cout << String{"All good!"} << std::endl;

	return 0;
}
