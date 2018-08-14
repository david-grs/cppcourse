#include "string.h"
#include <iostream>
#include <algorithm>

String::String()
{}

size_t strlen(const char* string)
{
	size_t lenght;
	for(lenght=0; string[lenght]; lenght++);
	return lenght;
}

String::String(const String& other)
{
	mSize = other.mSize;
	mCapacity = other.mCapacity;
	mData = std::make_unique<char[]>(mCapacity);
	for(size_t i=0; i<mSize; ++i)
	{
		mData[i] = other.mData[i];
	}
}

String::String(const char* other)
{
	mSize = strlen(other);
	mData = std::make_unique<char[]>(mSize);
	mCapacity = mSize;

	for(size_t i=0; i < mSize; ++i)
	{
		mData[i] = other[i];
	}
}

char& String::operator[] (size_t i)
{
	return mData[i];
}

char String::operator[] (size_t i) const
{
  return mData[i];
}

bool String::operator== (const String& other) const
{
	if(mSize != other.mSize)
	{
		return false;
	}

	for(size_t i=0; i < mSize; ++i)
	{
		if(mData[i] != other.mData[i])
		{
			return false;
		}
	}
	return true;
}

std::ostream& operator<< (std::ostream& os, const String& string)
{
	os << string.c_str();
	return os;
}



String& String::operator= (String other)
{
	std::swap(mSize, other.mSize);
	std::swap(mCapacity, other.mCapacity);
	std::swap(mData, other.mData);
	return *this;
}

String String::operator+ (const String& other) const
{
	String result = *this;
	result.mSize += other.mSize;
	result.mCapacity += other.mSize;
	for(size_t i = 0; i <= other.mSize; ++i)
	{
		result.mData[mSize+i] = other.mData[i];
	}
	return result;
}

String operator+ (const char* left, const String& right)
{
	return String(left) + right;
}

bool operator== (const char* left, const String& right)
{
  return String(left) == right;
}

bool operator== (std::string left, const String& right)
{
	return left == std::string(right);
}
