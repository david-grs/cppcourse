#include "sarray.h"

sarray::sarray(size_t maxSize) :
		mCapacity{maxSize}
{
}

sarray::sarray()
{
	mCapacity = 32;
}

void sarray::push_back(int element)
{
	if (size() + 1 > mCapacity)
		throw std::out_of_range("Array out of bounds");
	mData.push_back(element);
	std::sort(mData.begin(), mData.end());
}

int& sarray::operator[](size_t i)
{
	if (i >= mCapacity)
		throw std::out_of_range("Index out of bounds");
	return mData[i];
}
