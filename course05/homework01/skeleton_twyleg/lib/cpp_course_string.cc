// Some copyright 2020
#include "cpp_course_string.h"

#include <iostream>
#include <cstring>

namespace cppcourse {

String::String(const String& inputString) :
	mData(inputString.mData)
{}

String::String(String&& inputString) :
	mData(std::move(inputString.mData))
{}

String::String(const std::string& inputString)
{
	for (char c: inputString)
	{
		Append(c);
	}
}

String& String::Append(const String& inputString)
{
	for (auto c: inputString.mData)
	{
		Append(c);
	}

	return *this;
}

String& String::Append(char c)
{
	mData.push_back(c);
	return *this;
}

String::iter String::Erase(const iter& pos)
{
	return mData.erase(pos);	
}

char& String::at(size_t pos)
{
	if (pos > mData.size())
		throw std::length_error("Requested position exeeds string length");

	std::size_t i = 0;
	for (auto& c: mData)
	{
		if (i++ == pos)
			return c;
	}

	// Here be dragons
	return *mData.begin();
}

bool String::operator==(const String& rhs) const
{
	if (Size() != rhs.Size())
		return false;

	auto lhsIt = mData.begin();
	auto rhsIt = rhs.mData.begin();

	while (lhsIt != mData.end())
	{
		if (*lhsIt != *rhsIt)
			return false;
		++lhsIt;
		++rhsIt;
	}

	return true;
}

bool String::operator!=(const String& rhs) const
{
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	for (char c: str.mData)
	{
		stream << c;
	}

	return stream;
}


}
