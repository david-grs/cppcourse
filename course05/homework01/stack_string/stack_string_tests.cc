#include "stack_string.h"

#include <cassert>
#include <iostream>
#include <string>

namespace cppcourse::homework01 {

using namespace std::literals;

void TestEmpty()
{
	const char emptyChar[]{};

	StackString stackString;
	assert(stackString.Empty());
	assert(stackString.Size() == 0);
	assert(strcmp(stackString.GetValue(), emptyChar) == 0);
	assert(stackString.ToString() == ""s);

	stackString = StackString{emptyChar};
	assert(stackString.Empty());
	assert(stackString.Size() == 0);
	assert(strcmp(stackString.GetValue(), emptyChar) == 0);
	assert(stackString.ToString() == ""s);

	stackString = StackString{""s};
	assert(stackString.Empty());
	assert(stackString.Size() == 0);
	assert(strcmp(stackString.GetValue(), emptyChar) == 0);
	assert(stackString.ToString() == ""s);
}

void TestValidStringLength()
{
	const std::string testValue{"test input"};

	StackString stackString = StackString{testValue};
	assert(!stackString.Empty());
	assert(stackString.Size() == testValue.size());
	assert(strcmp(stackString.GetValue(), testValue.c_str()) == 0);
	assert(stackString.ToString() == testValue);

	stackString = StackString{testValue.c_str()};
	assert(!stackString.Empty());
	assert(stackString.Size() == testValue.size());
	assert(strcmp(stackString.GetValue(), testValue.c_str()) == 0);
	assert(stackString.ToString() == testValue);
}

void TestMaxStringLength()
{
	const std::string testValue(StackString::MAX_STRING_LENGTH, '*');

	StackString stackString = StackString{testValue};
	assert(!stackString.Empty());
	assert(stackString.Size() == StackString::MAX_STRING_LENGTH);
	assert(strcmp(stackString.GetValue(), testValue.c_str()) == 0);
	assert(stackString.ToString() == testValue);

	stackString = StackString{testValue.c_str()};
	assert(!stackString.Empty());
	assert(stackString.Size() == StackString::MAX_STRING_LENGTH);
	assert(strcmp(stackString.GetValue(), testValue.c_str()) == 0);
	assert(stackString.ToString() == testValue);
}

void TestInputExceedStringLength_ExpectRuntimeError()
{
	std::string maxLengthString(StackString::MAX_STRING_LENGTH+1, '*');

	try
	{
		StackString string = StackString{maxLengthString};
		assert(false);
	}
	catch (std::runtime_error error)
	{
		assert(error.what() == "String length exceeds MAX_STRING_LENGTH ("+ std::to_string(StackString::MAX_STRING_LENGTH) + ")"s);
	}

	try
	{
		StackString string = StackString{maxLengthString.c_str()};
		assert(false);
	}
	catch (std::runtime_error error)
	{
		assert(error.what() == "String length exceeds MAX_STRING_LENGTH ("+ std::to_string(StackString::MAX_STRING_LENGTH) + ")"s);
	}
}

void TestCharArrayWithIntermediateNullTerminator_ExpectShortestString()
{
	char testValue[7] = {'f', 'o','o', '\0', 'b', 'a','r'};

	StackString stackString = StackString{testValue};
	assert(sizeof (testValue) == 7);
	assert(stackString.Size() == 3);
	assert(strcmp(stackString.GetValue(), "foo") == 0);
	assert(stackString.ToString() == "foo"s);
}

void TestAppendToEmptyStackString()
{
	StackString empty;
	StackString foo{"foo"s};

	empty.Append(foo);

	assert(empty.Size() == 3);
	assert(strcmp(empty.GetValue(), "foo") == 0);
	assert(empty.ToString() == "foo"s);
}

void TestAppendWithEmptyStackString()
{
	StackString foo{"foo"s};
	StackString empty;

	foo.Append(empty);

	assert(foo.Size() == 3);
	assert(strcmp(foo.GetValue(), "foo") == 0);
	assert(foo.ToString() == "foo"s);
}

void TestAppendTo_ExceedsMaxStringLength_ExpectRuntimeError()
{
	StackString foo{"foo"s};
	const StackString maxStringLength(std::string(StackString::MAX_STRING_LENGTH, '*'));

	try
	{
		foo.Append(maxStringLength);
		assert(false);
	}
	catch (std::runtime_error error)
	{
		assert(error.what() == "String length to large to append"s);
	}
}

}

int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif

	using namespace cppcourse::homework01;

	std::cout << "Start testing.." << std::endl;

	TestEmpty();
	TestMaxStringLength();
	TestInputExceedStringLength_ExpectRuntimeError();
	TestCharArrayWithIntermediateNullTerminator_ExpectShortestString();
	TestAppendToEmptyStackString();
	TestAppendWithEmptyStackString();
	TestAppendTo_ExceedsMaxStringLength_ExpectRuntimeError();

	std::cout << "All tests ended successfully" << std::endl;

	return 0;
}
