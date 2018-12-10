#include "vector.h"

VectorInt::VectorInt(){
    vectorSize = 0;
}

int VectorInt::size ()
{
	return vectorSize;
}

int VectorInt::capacity()
{
	return vectorData.size();
}

int VectorInt::back()
{
	if (size() == 0)
	{
		throw std::out_of_range("empty VectorInt");
	}
	return vectorData[size() - 1];
}

void VectorInt::push_back(int newElement)
{
	if (size() == capacity())
	{
		throw std::out_of_range("VectorInt out of range");
	}
	vectorData[size()] = newElement;
	vectorSize++;
}

void VectorInt::clear()
{
	vectorSize = 0;
}
