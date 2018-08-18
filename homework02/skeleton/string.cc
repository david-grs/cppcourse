#include "string.h"
#include <cstring>

String::String():
    mCharacters(std::make_unique<char[]>(0)),
    mSize(0),
    mCapacity(0)
{}

String::String(const String& str) :
    String(str.c_str())
{}

String::String(const char* str) {
   mSize = strlen(str);
   mCapacity = mSize;
   mCharacters = std::make_unique<char[]>(mSize);

   for (int i = 0; i < mSize; ++i)
       mCharacters[i] = str[i];
}

String::operator std::string () const
{
    return std::string(mCharacters.get());
}

bool String::empty() const
{
    return mSize == 0;
}

int String::size() const
{
    return mSize;
}

int String::capacity() const
{
    return mCapacity;
}

char* String::c_str() const
{
    return mCharacters.get();
}

char&  String::operator[](int index) const
{
    return mCharacters[index];
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    return os << str.c_str();
}

String operator+(const char* left, const String& right)
{
    char* newArray = new char[strlen(left) + right.size()];
    std::strcpy(newArray, left);
    std::strcat(newArray, right.c_str());
    return String(newArray);
}

bool operator==(const char* tmp, String string)
{
    return strcmp(tmp, string.c_str()) == 0;
}

bool operator==(std::string tmp, String string)
{
    return tmp == string.c_str();
}
