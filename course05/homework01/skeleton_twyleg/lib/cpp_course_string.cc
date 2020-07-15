// Some copyright 2020

#include "cpp_course_string.h"

#include <iostream>
#include <cstring>

namespace cppcourse {

String::String()
{
	mData[0] = '\0';
	mSize = 0;
}

String::String(const std::string& inputString)
{
	if ((inputString.length() + 1) > STRING_MAX_LENGTH)
		throw std::length_error("Error: input string exceeds internal memory limit");

	std::memcpy(mData.data(), inputString.data(), inputString.length());
	mData[inputString.length()] = '\0';
	mSize = inputString.length();
}

String& String::append(const String& inputString)
{
	if ((mSize + inputString.Size() + 1) > STRING_MAX_LENGTH)
		throw std::length_error("Error: Resulting string would: exceed internal memory limit");

	std::memcpy(mData.data()+mSize, inputString.mData.data(), inputString.Size());
	mSize += inputString.Size();
	mData[mSize] = '\0';

	return *this;
}

bool String::operator==(const String& rhs) const
{
	return !std::strcmp(mData.data(), rhs.c_str());
}

bool String::operator!=(const String& rhs) const
{
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& stream, String str)
{
	return stream << str.mData.data();
}


}
