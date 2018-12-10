#include "vector.h"

int VectorInt::capacity() const
{
	return mMaxSize;
}

int VectorInt::size() const
{
	return mSize;
}

int VectorInt::back() const
{
	return mData[mSize -1];
}

void VectorInt::push_back(const int& x)
{
	mData[mSize++] = x;
}

void VectorInt::clear()
{
	mSize = 0;
}
