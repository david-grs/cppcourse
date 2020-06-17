// Some copyright 2020

#include "string.h"

namespace cppcourse {

String::String()
{
    mData[0] = '\0';
    mSize = 0;
}

String::String(std::string inputString)
{
    if ((inputString.length() + 1) > STRING_MAX_LENGTH)
        throw std::runtime_error("Error: input string exceeds internal memory limit");

    memcpy(mData.data(), inputString.data(), inputString.length());
    mData[inputString.length()] = '\0';
    mSize = inputString.length();
}

String& String::append(const String& inputString)
{
    if ((mSize + inputString.Size() + 1) > STRING_MAX_LENGTH)
        throw std::runtime_error("Error: Resulting string would exceed internal memory limit");

    for (size_t i=0; i<inputString.Size(); ++i)
    {
        mData[mSize++] = inputString.mData[i];
    }

    mData[mSize] = '\0';

    return *this;
}

std::ostream& operator<<(std::ostream& stream, String str)
{
    return stream << str.mData.data();
}

bool operator==(const String& lhs, const String& rhs)
{
    if (lhs.Size() != rhs.Size())
        return false;

    const char* lhsCStr = lhs.c_str();
    const char* rhsCStr = rhs.c_str();

    for (size_t i=0; i<lhs.Size(); ++i)
    {
        if (lhsCStr[i] != rhsCStr[i])
            return false;
    }

    return true;
}

bool operator!=(const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}

}
