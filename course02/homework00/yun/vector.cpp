#include "vector.h"

VectorInt::VectorInt(): mSize(0) {}

int VectorInt::size () const
{
	return mSize;
}

int VectorInt::capacity() const
{
	return mData.size();
}

int VectorInt::back() const
{
	if (size() == 0)
	{
		throw std::out_of_range("empty VectorInt");
	}
	return mData[size() - 1];
}
int& VectorInt::back()
{
	if (size() == 0)
	{
		throw std::out_of_range("empty VectorInt");
	}
	return mData[size() - 1];
}

void VectorInt::push_back(int newElement)
{
	if (size() == capacity())
	{
		throw std::out_of_range("VectorInt out of range");
	}
	mData[size()] = newElement;
	mSize++;
}

void VectorInt::clear()
{
	mSize = 0;
}
