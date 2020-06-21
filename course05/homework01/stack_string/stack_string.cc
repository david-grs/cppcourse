#include "stack_string.h"

#include <iostream>

namespace cppcourse::homework01 {

StackString::StackString(const std::string& input)
{
    if (input.length() > MAX_STRING_LENGTH)
		throw std::runtime_error("String length exceeds MAX_STRING_LENGTH (" + std::to_string(MAX_STRING_LENGTH) + ")");

    mTop = input.length();
	strcpy(mData, input.c_str());
	mData[mTop+1] = '\0';
}

StackString::StackString(const char* input)
{
	if (strlen(input) > MAX_STRING_LENGTH)
		throw std::runtime_error("String length exceeds MAX_STRING_LENGTH (" + std::to_string(MAX_STRING_LENGTH) + ")");

	mTop = strlen(input);
	strcpy(mData, input);
	mData[mTop+1] = '\0';
}

bool StackString::Empty() const
{
	return mTop == 0;
}

std::size_t StackString::Size() const
{
	return mTop;
}

const char* StackString::GetValue() const
{
	return &mData[0];
}

std::string StackString::ToString() const
{
	return std::string(mData);
}

void StackString::Append(const StackString& string)
{
	size_t newSize = Size() + string.Size();
	if (newSize > MAX_STRING_LENGTH)
		throw std::runtime_error("String length to large to append");

	strcpy(&mData[mTop], string.GetValue());
	mTop = newSize;
	mData[mTop+1] = '\0';
}

}
