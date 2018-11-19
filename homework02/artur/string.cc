#include "string.h"
#include <iostream>
#include <algorithm>

String::String()
  : mSize(0)
  , mCapacity(0)
  , mData(nullptr)
{
}

String::String(const String& other)
{
  mSize = other.mSize;
  mCapacity = other.mCapacity;
  mData = std::make_unique<char[]>(mCapacity);
  for(int i=0; i<mSize; ++i)
    {
      mData[i] = other.mData[i];
    }
}

String& String::operator=(String other)
{
  std::swap(mSize,other.mSize);
  std::swap(mCapacity,other.mCapacity);
  std::swap(mData,other.mData);
  return *this;
}

String::String(char other)
{
  mSize = 1;
  mCapacity = 1;
  mData = std::make_unique<char[]>(1);
  mData[0] = other;
}

String& String::operator=(char other)
{
  mSize = 1;
  mCapacity = 1;
  mData = std::make_unique<char[]>(1);
  mData[0] = other;
  return *this;
}

size_t strlen(const char *str)
{
  const char *s;
  for (s = str; *s; ++s);
  return s-str;
}

String::String(const char* other)
{
  mSize = strlen(other);
  mData = std::make_unique<char[]>(mSize);
  mCapacity = mSize;

  int i;
  for(i=0;i<mSize;++i)
    {
      mData[i] = other[i];
    }
}

String& String::operator=(const char* other)
{
  return *this;
}

bool String::operator==(const String& other) const
{
  if(size() != other.size())
    {
      return false;
    }
  else
    {
      for(int i = 0; i<size(); ++i)
	{
	  if(mData[i] != other.mData[i])
	    {
	      return false;
	    }
	}
    }
  return true;
}

String String::operator+(const String& other) const
{
  String result;
  result.mSize = mSize+other.mSize;
  result.mCapacity = result.mSize;
  result.mData = std::make_unique<char[]>(result.mSize);
  for(int i = 0; i < mSize; ++i)
    {
      result.mData[i] = mData[i];
    }
  for(int i = 0; i < other.mSize; ++i)
    {
      result.mData[mSize+i] = other.mData[i];
    }
  return result;
}

String String::operator+(const char* other) const
{
  String otherString = String(other);
  return *this + otherString;
}

char String::operator[](int i) const
{
  return mData[i];
}

char& String::operator[](int i)
{
  return mData[i];
}

int String::size() const
{
  return mSize;
}

int String::capacity() const
{
  return mCapacity;
}

bool String::empty() const
{
  return String::size() <= 0;
}

char* String::c_str() const
{
  return mData.get();
}

void String::grow()
{
  
}

std::ostream& operator<<(std::ostream& os, const String& other)
{
  os << other.c_str();
  return os;
}

String operator+(const char* first, const String& second)
{
  return String(first) + second;  
}

bool operator==(const char* first, const String& second)
{
  return String(first) == second;
}

bool operator==(std::string first, const String& second)
{
  return first == std::string(second);
}
