#include "sortedarray.h"

SortedArray::SortedArray(std::size_t maxSize) : 
	mMaxSize{maxSize}
{
}

void SortedArray::push_back(int element)
{
	if (mVector.size() == mMaxSize)
		throw std::runtime_error("The array is already full");
	mVector.push_back(element);
	std::sort(mVector.begin(), mVector.end());
}

int SortedArray::operator[](std::size_t index)
{
	return mVector[index];
}

int SortedArray::at(std::size_t index)
{
	return mVector.at(index);
}

bool SortedArray::empty()
{
	return mVector.empty();
}

std::size_t SortedArray::size()
{
	return mVector.size();
}

std::size_t SortedArray::max_size()
{
	return mMaxSize;
}

std::vector<int>::iterator SortedArray::begin()
{
	return mVector.begin();
}

std::vector<int>::iterator SortedArray::end()
{
	return mVector.end();
}
