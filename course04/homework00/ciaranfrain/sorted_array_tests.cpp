#include "sorted_array_tests.h"

#include <algorithm>
#include <iostream>
#include <vector>

const int SortedArrayTests::mDefaultMaxSize = 10;

SortedArrayTests::SortedArrayTests(): mSortedArray(mDefaultMaxSize)
{}

void SortedArrayTests::RunTests()
{
	std::cout << "Running tests..." << std::endl;

	RunTest("ShouldInitialiseEmpty",             [this]() { return ShouldInitialiseEmpty(); });
	RunTest("ShouldInsertOneElement",            [this]() { return ShouldInsertOneElement(); });
	RunTest("ShouldRetrieveCorrectElementValue", [this]() { return ShouldRetrieveCorrectElementValue(); });
	RunTest("ShouldThrowOnExceedingSize",        [this]() { return ShouldThrowOnExceedingSize(); });
	RunTest("ShouldInsertLesserValueAtFront",    [this]() { return ShouldInsertLesserValueAtFront(); });
	RunTest("ShouldInsertGreaterValueAtBack",    [this]() { return ShouldInsertGreaterValueAtBack(); });
	RunTest("ShouldSortElements",                [this]() { return ShouldSortElements(); });
}

void SortedArrayTests::Reset(std::size_t size = mDefaultMaxSize)
{
	mSortedArray = SortedArray(size);
}

bool SortedArrayTests::RunTest(const std::string& testTitle, std::function<bool()> test)
{
	std::cout << "SortedArrayTests::" << testTitle << ": ";
	const bool testPassed = test();
	if (testPassed)
	{
		std::cout << "Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Failed" << std::endl;
		return false;
	}
}
bool SortedArrayTests::ShouldInitialiseEmpty()
{
	Reset();

	if (mSortedArray.empty())
		return true;
	else
		return false;
}

bool SortedArrayTests::ShouldInsertOneElement()
{
	Reset();

	mSortedArray.Insert(5);
	if (mSortedArray.size() == 1)
		return true;
	else
		return false;
}

bool SortedArrayTests::ShouldRetrieveCorrectElementValue()
{
	Reset();

	mSortedArray.Insert(5);
	if (mSortedArray[0] == 5)
		return true;
	else
		return false;
}

bool SortedArrayTests::ShouldThrowOnExceedingSize()
{
	Reset(1);

	mSortedArray.Insert(0);
	try
	{
		mSortedArray.Insert(1);
	}
	catch (std::length_error)
	{
		return true;
	}
	return false;
}

bool SortedArrayTests::ShouldInsertLesserValueAtFront()
{
	Reset();

	mSortedArray.Insert(0);
	mSortedArray.Insert(-1);
	if (mSortedArray[0] == -1)
		return true;
	else
		return false;
}

bool SortedArrayTests::ShouldInsertGreaterValueAtBack()
{
	Reset();

	mSortedArray.Insert(0);
	mSortedArray.Insert(1);
	if (mSortedArray[1] == 1)
		return true;
	else
		return false;
}

bool SortedArrayTests::ShouldSortElements()
{
	Reset();
	std::vector<int> inputValues = {1, 55, 23, 1, -3, 1000, -53, 17, 32, 9};
	for (const auto& n : inputValues)
	{
		mSortedArray.Insert(n);
	}
	std::sort(inputValues.begin(), inputValues.end());
	for (int i=0; i<inputValues.size(); i++)
	{
		if (mSortedArray[i] != inputValues[i])
			return false;
	}
	return true;
}
