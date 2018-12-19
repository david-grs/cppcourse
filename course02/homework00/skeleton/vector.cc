#include "vector.h"
#include <cassert>

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
	assert(mSize > 0);

	return mData[mSize - 1];
}

int& VectorInt::back()
{
	assert(mSize > 0);
	return mData[mSize - 1];
}

void VectorInt::push_back(int x)
{
	assert(mSize < capacity());
    
    mData[mSize++] = x;
}

void VectorInt::clear()
{
	mSize = 0;
}
