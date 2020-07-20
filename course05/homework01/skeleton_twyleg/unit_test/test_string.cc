// Some copyright 2020
#include <gtest/gtest.h>

#include <cpp_course_string.h>

#include <iostream>
#include <sstream>
#include <cassert>

namespace cppcourse::testing {

constexpr std::size_t STRING_TEST_LENGTH = 512;

TEST(CreationTest, NoStringProvided_CreateString_StringCreated)
{
	std::string inputString;
	cppcourse::String str(inputString);
}

TEST(CreationTest, NonEmptyStdString_CreateString_StringCreated)
{
	std::string inputString("foobar");
	cppcourse::String str(inputString);
}

TEST(CreationTest, EmptyString_CopyConstruct_StringCopyCreated)
{
	cppcourse::String srcString;
	cppcourse::String dstString(srcString);

	EXPECT_TRUE(srcString.Empty());
	EXPECT_TRUE(dstString.Empty());
	EXPECT_EQ(srcString, dstString);
}

TEST(CreationTest, NonEmptyString_CopyConstruct_StringCopyCreated)
{
	cppcourse::String srcString("foobar");
	cppcourse::String dstString(srcString);

	EXPECT_EQ(srcString, dstString);
}

TEST(CreationTest, NonEmptyString_MoveConstruct_StringMoved)
{
	cppcourse::String srcString("foobar");
	cppcourse::String dstString(std::move(srcString));

	EXPECT_TRUE(srcString.Empty());
	EXPECT_EQ(dstString, cppcourse::String("foobar"));
}

TEST(EmptynessTest, EmptyString_CheckEmptyness_True)
{
	cppcourse::String str;
	EXPECT_TRUE(str.Empty());
}

TEST(EmptynessTest, NonEmptyString_CheckEmptyness_False)
{
	cppcourse::String str("foobar");
	EXPECT_FALSE(str.Empty());
}

TEST(SizeTest, EmptyString_CheckEmptyness_True)
{
	cppcourse::String str;
	EXPECT_TRUE(str.Empty());
}

TEST(SizeTest, NonEmptyString_CheckSize_SizeCorrect)
{
	cppcourse::String str("foobar");
	EXPECT_EQ(str.Size(), 6);
}

TEST(OperatorTest, NonEmptyString_StreamToStringstream_OutputCorrect)
{
	std::string inputString = "foobar";
	cppcourse::String str(inputString);

	std::stringstream ss;
	ss << str;

	EXPECT_EQ(ss.str(), inputString);
}

TEST(OperatorTest, EqualStrings_CheckEquality_True)
{
	cppcourse::String stringA("foobar");
	cppcourse::String stringB("foobar");

	EXPECT_TRUE(stringA == stringB);
}

TEST(OperatorTest, UnequalStrings_CheckEquality_False)
{
	cppcourse::String stringA("foobarfoo");
	cppcourse::String stringB("foobar");

	EXPECT_FALSE(stringA == stringB);
}

TEST(OperatorTest, EqualStrings_CheckUnequality_False)
{
	cppcourse::String stringA("foobar");
	cppcourse::String stringB("foobar");

	EXPECT_FALSE(stringA != stringB);
}

TEST(OperatorTest, UnequalStrings_CheckUnequality_True)
{
	cppcourse::String stringA("foobarfoo");
	cppcourse::String stringB("foobar");

	EXPECT_TRUE(stringA != stringB);
}

TEST(AppendTest, EmptyString_AppendString_StringAppended)
{
	cppcourse::String stringA("foobar");
	cppcourse::String stringB;

	stringB.Append(stringA);

	EXPECT_EQ(stringB, cppcourse::String("foobar"));
}

TEST(AppendTest, NonEmptyString_AppendString_StringAppended)
{
	cppcourse::String stringA("foobar");
	cppcourse::String stringB("foobar");

	stringB.Append(stringA);

	EXPECT_EQ(stringB, cppcourse::String("foobarfoobar"));
}

TEST(EraseTest, NonEmptyString_EraseFirstChar_CharErased)
{
	cppcourse::String stringA("abc");
	cppcourse::String stringB("bc");

	stringA.Erase(stringA.begin());

	EXPECT_EQ(stringA, stringB);
}

TEST(EraseTest, NonEmptyString_EraseMiddleChar_CharErased)
{
	cppcourse::String stringA("abc");
	cppcourse::String stringB("ac");

	stringA.Erase(++stringA.begin());

	EXPECT_EQ(stringA, stringB);
}

TEST(EraseTest, NonEmptyString_EraseLastChar_CharErased)
{
	cppcourse::String stringA("abc");
	cppcourse::String stringB("ab");

	stringA.Erase(++(++stringA.begin()));

	EXPECT_EQ(stringA, stringB);
}

TEST(AtTest, NonEmptyString_SetFirstChar_CharSet)
{
	cppcourse::String stringA("abc");
	cppcourse::String stringB("xbc");

	stringA.at(0) = 'x';

	EXPECT_EQ(stringA, stringB);
}

TEST(AtTest, NonEmptyString_EraseLastChar_CharErased)
{
	cppcourse::String stringA("abc");

	EXPECT_THROW(stringA.at(4) = 'x', std::length_error);

}

}

