#include "sorted_array.h"

#include <algorithm>

void SortedArray::push_back(int value)
{
	if (mSize == MaxSize)
	{
		throw std::out_of_range("capacity exceeded");
	}

	mData[mSize] = value;
	mSize += 1;

	std::sort(mData.begin(), mData.begin() + mSize);
}
