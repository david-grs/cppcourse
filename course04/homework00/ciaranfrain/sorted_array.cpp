#include "sorted_array.h"

#include <algorithm>
#include <stdexcept>

SortedArray::SortedArray(std::size_t maxSize): mMaxSize(maxSize)
{}

void SortedArray::Insert(int n)
{
	if (size() == mMaxSize)
		throw std::length_error("error: sorted array is at maximum capacity");

	mStorage.push_back(n);
	std::sort(mStorage.begin(), mStorage.end());
}

const int& SortedArray::Get(int n) const
{
	return mStorage[n];
}
