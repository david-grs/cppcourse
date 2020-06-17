// Some copyright 2020

#include "string.h"

#include <iostream>
#include <sstream>
#include <cassert>

void TestCreate_EmptyString_StringCreated()
{
    std::string inputString;
    cppcourse::String str(inputString);
}

void TestCreate_ValidString_StringCreated()
{
    std::string inputString("foobar");
    cppcourse::String str(inputString);
}

void TestCreate_OversizedString_ExceptionThrown()
{
    std::string inputString;

    for (size_t i=0; i<cppcourse::String::STRING_MAX_LENGTH+1; ++i)
    {
        inputString.push_back('+');
    }

    try
    {
        cppcourse::String str(inputString);
        assert(1==0);
    }
    catch (const std::runtime_error& error)
    {}

}

void TestEmpty_EmptyString_Empty()
{
    cppcourse::String str;
    assert(str.Empty());
}

void TestEmpty_NonEmptyString_NotEmpty()
{
    cppcourse::String str("foobar");
    assert(!str.Empty());
}

void TestSize_EmptyString_CorrectSize()
{
    cppcourse::String str;
    assert(str.Empty());
}

void TestSize_NonEmptyString_CorrectSize()
{
    cppcourse::String str("foobar");
    assert(str.Size() == 6);
}

void TestStream_NonEmptyString_CorrectOutputStream()
{
    std::string inputString = "foobar";
    cppcourse::String str(inputString);

    std::stringstream ss;
    ss << str;

    assert(ss.str() == inputString);
}

void TesteEqualOperator_EqualStrings_ReturnTrue()
{
    cppcourse::String stringA("foobar");
    cppcourse::String stringB("foobar");

    assert(stringA == stringB);
}

void TestEqualOperator_UnequalStrings_ReturnFalse()
{
    cppcourse::String stringA("foobarfoo");
    cppcourse::String stringB("foobar");

    assert(!(stringA == stringB));
}

void TestUnequalOperator_EqualStrings_ReturnFalse()
{
    cppcourse::String stringA("foobar");
    cppcourse::String stringB("foobar");

    assert(!(stringA != stringB));
}

void TestUnequalOperator_UnequalStrings_ReturnTrue()
{
    cppcourse::String stringA("foobarfoo");
    cppcourse::String stringB("foobar");

    assert(stringA != stringB);
}

void TestAppend_EmptyString_StringAppended()
{
    cppcourse::String stringA("foobar");
    cppcourse::String stringB;

    stringB.append(stringA);

    assert(stringB == cppcourse::String("foobar"));
}

void TestAppend_NonEmptyString_StringAppended()
{
    cppcourse::String stringA("foobar");
    cppcourse::String stringB("foobar");

    stringB.append(stringA);

    assert(stringB == cppcourse::String("foobarfoobar"));
}

void TestAppend_OversizedString_ExceptionThrown()
{
    cppcourse::String stringA;
    cppcourse::String stringB("a");

    for (size_t i=0; i<cppcourse::String::STRING_MAX_LENGTH-1; ++i)
    {
        stringA.append(stringB);
    }

    try
    {
        stringA.append(stringB);
        assert(1==0);
    }
    catch (const std::runtime_error& error)
    {}
}

int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif

    TestCreate_EmptyString_StringCreated();
    TestCreate_ValidString_StringCreated();
    TestCreate_OversizedString_ExceptionThrown();

    TestEmpty_EmptyString_Empty();
    TestEmpty_NonEmptyString_NotEmpty();

    TestSize_EmptyString_CorrectSize();
    TestSize_NonEmptyString_CorrectSize();

    TestStream_NonEmptyString_CorrectOutputStream();

    TesteEqualOperator_EqualStrings_ReturnTrue();
    TestEqualOperator_UnequalStrings_ReturnFalse();

    TestUnequalOperator_EqualStrings_ReturnFalse();
    TestUnequalOperator_UnequalStrings_ReturnTrue();

    TestAppend_EmptyString_StringAppended();
    TestAppend_NonEmptyString_StringAppended();
    TestAppend_OversizedString_ExceptionThrown();

	return 0;
}
