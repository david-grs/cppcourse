#include "string.h"
#include<string>
#include <cassert>

void TestEmpty()
{
	String str;
	assert(str.Empty());
}

void Test_Equals_DifferentStringsGiven_ShouldNotEqualEachOther(){
	// Arrange
	std::string helloWord("Hello!"); 
	const char* myword = "DIFFERNT!";
	auto expected = String(myword);

	// Act
	auto actual = String(helloWord);

	// Assert
	assert(actual != expected);
}

void Test_Constructor_SameStringsGiven_ShouldEqualEachOther(){
	// Arrange
	std::string helloWord("Hello!"); 
	const char* myword = "Hello!";
	auto expected = String(myword);

	// Act
	auto actual = String(helloWord);

	// Assert
	assert(actual == expected);
}
void Test_NotEquals_TwoDifferentStrings_ShouldNotBeEqual()
{
	// Arrange
	auto first = String("Not the same");
	auto second = String("As the Other one");

	// Act
	auto result = first != second;

	// Assert 
	assert(result);
}


void Test_Concatenate_TooLongStringsGiven_ShouldGiveException(){
	// Arrange
	assert(false);
	// Act / Assert
}

void Test_Concatenate_ValidStringsGiven_ShouldBeConcatenatedCorrectly(){
	// Arrange
	auto first = String("Hello ");
	auto second = String("World!");
	auto expected = String("Hello World!");

	// Act
	auto actual = first + second;

	// Assert
	assert(actual == expected);
}
int main()
{
#ifdef NDEBUG
#error "This file needs to be built with Debug flags"
#endif

	TestEmpty();


	Test_Equals_DifferentStringsGiven_ShouldNotEqualEachOther();
	Test_Constructor_SameStringsGiven_ShouldEqualEachOther();
	Test_Concatenate_ValidStringsGiven_ShouldBeConcatenatedCorrectly();
	// TODO: other tests

	return 0;
}
