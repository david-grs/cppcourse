#pragma once

#include "sorted_array.h"
#include <functional>
#include <string>

class SortedArrayTests
{
public:
	SortedArrayTests();
	void RunTests();

private:
	bool RunTest(const std::string&, std::function<bool()>);
	void Reset(std::size_t);

	bool ShouldInitialiseEmpty();
	bool ShouldInsertOneElement();
	bool ShouldRetrieveCorrectElementValue();
	bool ShouldThrowOnExceedingSize();
	bool ShouldInsertLesserValueAtFront();
	bool ShouldInsertGreaterValueAtBack();
	bool ShouldSortElements();

	SortedArray mSortedArray;
	static const int mDefaultMaxSize;
};
