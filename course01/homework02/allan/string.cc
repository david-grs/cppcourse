#include "string.h"

#include <cstring>
#include <iostream>
String::String(const char *ch)
  : String(ch, strlen(ch) + 1)
{
}

String::String()
   :String("", 1)
{
}

String::String(const String& other)
  : String(other.c_str(), other.capacity())
{
}


String::String(const char *ch, int capacity)
  : mCapacity(capacity),
    mData(std::make_unique<char []>(mCapacity))
{
  strcpy(mData.get(), ch);
}

String::~String()
{
}

String& String::operator=(String other)
{
  std::swap(mCapacity, other.mCapacity);
        std::swap(mData, other.mData);
}

bool String::empty() const
{
        return size() == 0;
}

const char* String::c_str() const
{
        return mData.get();
}

String::operator std::string() const
{
        return std::string(c_str());
}

char& String::operator[](int pos)
{
  return mData[pos];
}

const char& String::operator[](int pos) const
{
  return mData[pos];
}

int String::size() const
{
        return strlen(mData.get());
}

int String::capacity() const
{
        return mCapacity;
}


std::ostream& operator<<(std::ostream& ostr, const String& str)
{
        ostr << str.c_str();
        return ostr;
}


String operator+(const char *lhs, const String& rhs)
{
  std::unique_ptr<char []> temp = std::make_unique<char []>(strlen(lhs) + rhs.capacity());
  strcpy(temp.get(), lhs);
  strcat(temp.get(), rhs.c_str());
  return String(temp.get());
}

bool operator==(const char *lhs, String rhs)
{
        return strcmp(lhs, rhs.c_str()) == 0;
}

bool operator==(String lhs, const char *rhs)
{
  return strcmp(lhs.c_str(), rhs) == 0;
}

bool operator==(const std::string lhs, const String rhs)
{
  return lhs.c_str() == rhs;
}

