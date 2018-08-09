#include "string.h"
#include <algorithm>
#include <string>

size_t strlen(const char* data) 
{
	size_t length = 0;
	while (*data != '\0')
	{
		data++;
		length++;
	}
	return length;
}

String::String():String::String(1)
{}

String::String(const size_t capacity):
		mLength(ZERO_SIZE),
		mCapacity(capacity),
		mData(std::make_unique<char[]>(capacity))
{}

String::String(const char* other):
		mLength(strlen(other)),
		mCapacity((mLength * 2) + 1),
		mData(std::make_unique<char[]>(mCapacity))
{
	for(int i = 0; i < mLength; ++i)
	{
		mData[i] = other[i];
	}
}

String::String(const String& other):
		mLength(other.mLength),
		mCapacity(other.mCapacity),
		mData(std::make_unique<char[]>(mCapacity))
{
	for(size_t i = 0; i < mLength; i++) 
	{
		mData[i] = other.mData[i];
	}
}

String& String::operator=(String other)
{
	std::swap(mData, other.mData);
	std::swap(mLength, other.mLength);
	std::swap(mCapacity, other.mCapacity);
	return *this;
}

String& String::operator+(const String& other)
{	
	for(std::size_t i = 0; i < other.mLength; i++) 
	{		
		if (mLength == mCapacity)
		{
		  resize();
		}

		mData[mLength] = other.mData[i];
		mLength++;
	}

	return *this;
}

bool String::operator==(const String& other) const
{
	if(mLength != other.mLength)
	{
		return false;
	}

	for(size_t i = 0; i < mLength; ++i)
	{
		if(mData[i] != other.mData[i])
		{
			return false;
		}
	}
	return true;
}

bool String::empty() const
{
	return mLength == ZERO_SIZE;
}

size_t String::size() const
{
	return mLength;
}

size_t String::capacity() const
{
	return mCapacity;
}

char* String::c_str() const
{
	return mData.get();
}

void String::resize()
{
	std::unique_ptr<char[]> newData(new char[mCapacity*2 + 1]);
	std::copy_n(mData.get(), mLength, newData.get());
	mData = std::move(newData);
}