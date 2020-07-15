// Some copyright 2020
#include <gtest/gtest.h>

#include <cpp_course_string.h>

#include <iostream>
#include <sstream>
#include <cassert>

namespace cppcourse::testing {

TEST(CreateString, EmptyString_StringCreated)
{
	std::string inputString;
	cppcourse::String str(inputString);
}

TEST(CreateString, ValidString_StringCreated)
{
	std::string inputString("foobar");
	cppcourse::String str(inputString);
}

TEST(CreateString, OversizedString_ExceptionThrown)
{
	std::string inputString;
	for (size_t i=0; i<cppcourse::String::STRING_MAX_LENGTH+1; ++i)
		inputString.push_back('+');

	EXPECT_THROW(cppcourse::String(inputString), std::length_error);
}

TEST(EmptyCheck, EmptyString_Empty)
{
	cppcourse::String str;
	EXPECT_TRUE(str.Empty());
}

TEST(EmptyCheck, NonEmptyString_NotEmpty)
{
	cppcourse::String str("foobar");
	EXPECT_FALSE(str.Empty());
}

TEST(SizeCheck, EmptyString_CorrectSize)
{
	cppcourse::String str;
	EXPECT_TRUE(str.Empty());
}

TEST(SizeCheck, NonEmptyString_CorrectSize)
{
	cppcourse::String str("foobar");
	EXPECT_EQ(str.Size(), 6);
}

TEST(StreamOperator, NonEmptyString_CorrectOutputStream)
{
	std::string inputString = "foobar";
	cppcourse::String str(inputString);

	std::stringstream ss;
	ss << str;

	EXPECT_EQ(ss.str(), inputString);
}

TEST(EqualOperator, EqualStrings_ReturnTrue)
{
	cppcourse::String stringA("foobar");
	cppcourse::String stringB("foobar");

	EXPECT_TRUE(stringA == stringB);
}

TEST(EqualOperator, UnequalStrings_ReturnFalse)
{
	cppcourse::String stringA("foobarfoo");
	cppcourse::String stringB("foobar");

	EXPECT_FALSE(stringA == stringB);
}

TEST(UnequalOperator, EqualStrings_ReturnFalse)
{
	cppcourse::String stringA("foobar");
	cppcourse::String stringB("foobar");

	EXPECT_FALSE(stringA != stringB);
}

TEST(UnequalOperator, UnequalStrings_ReturnTrue)
{
	cppcourse::String stringA("foobarfoo");
	cppcourse::String stringB("foobar");

	EXPECT_TRUE(stringA != stringB);
}

TEST(Append, EmptyString_StringAppended)
{
	cppcourse::String stringA("foobar");
	cppcourse::String stringB;

	stringB.append(stringA);

	EXPECT_EQ(stringB, cppcourse::String("foobar"));
}

TEST(Append, NonEmptyString_StringAppended)
{
	cppcourse::String stringA("foobar");
	cppcourse::String stringB("foobar");

	stringB.append(stringA);

	EXPECT_EQ(stringB, cppcourse::String("foobarfoobar"));
}

TEST(Append, OversizedString_ExceptionThrown)
{
	cppcourse::String stringA;
	cppcourse::String stringB("a");
	for (size_t i=0; i<cppcourse::String::STRING_MAX_LENGTH-1; ++i)
		stringA.append(stringB);

	EXPECT_THROW(stringA.append(stringB), std::length_error);
}

}

