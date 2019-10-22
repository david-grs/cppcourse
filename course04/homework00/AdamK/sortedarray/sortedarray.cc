#include "sortedarray.h"

#include <algorithm>

void SortedArray::push_back(int element)
{
	if (mSize == mArray.max_size())
		throw std::runtime_error("The array is already full");
	mArray[mSize] = element;
	std::sort(mArray.begin(), mArray.begin() + mSize + 1);
	++mSize;
}
