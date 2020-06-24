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

void Test_Constructor_DefaultUsed_SizeIsZero(){
	// Arrange / Act
	String str;

	// Assert
	assert(str.Size() == 0);
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
	int individual_lengths = 600;
	String first;
	bool caught = false;
	String second;
	String toAdd{"a"};
	for(int i =0; i < individual_lengths; ++i) {
		first += toAdd;
		second += toAdd;
	}
	
	// Act / Assert
	try{
		first + second;
	}
	catch(const std::length_error& le)
	{
		caught = true;
	}
	assert(caught);
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

	Test_Constructor_DefaultUsed_SizeIsZero();
	Test_Constructor_SameStringsGiven_ShouldEqualEachOther();
	Test_NotEquals_TwoDifferentStrings_ShouldNotBeEqual();
	Test_Concatenate_TooLongStringsGiven_ShouldGiveException();
	Test_Concatenate_ValidStringsGiven_ShouldBeConcatenatedCorrectly();


	return 0;
}
