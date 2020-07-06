#include "string.h"

String::String() :
	mSizeOfString(0)
{
}

String::String(const char* input) :
	mSizeOfString(0)
{
	ParseChar(input)
}
String::String(const std::string& strInput) :
	mSizeOfString(0)
{
	ParseChar(strInput.c_str());
}

String::String(const char &mInternalChars[])
{
	ParseChar(mInternalChars);
}

void String::ParseChar(const char mInternalChars[])
{
	char currentChar = mInternalChars[0];
	std::size_t currentIndex = 0;
	while (currentChar != '\0')
	{
		mInternalChars[currentIndex] = currentChar;
		currentIndex++;
		currentChar = mInternalChars[currentIndex];
	}
	mSizeOfString = currentIndex;
}

char String::CharAt(int i)
{
	return mInternalChars[i];
}

String String::operator+=(const String &other)
{
	return *this + other;
}

String String::operator+(const String &other)
{
	std::size_t totalLength = Size() + other.Size();
	if (totalLength > MAX_STRING_SIZE)
	{
		throw std::length_error("Can't concatenate more than 1024 in total");
	}
	int indexStart = (int) Size();
	for (int i = 0; i <= indexStart; i++)
	{
		mInternalChars[indexStart + i] = other.CharAt(i);
	}
	mSizeOfString = (std::size_t)totalLength;
	return *this;
}

bool String::operator==(const String &other)
{
	if (Size() != other.Size())
	{
		return false;
	}
	for (int i = 0; i < (int)Size(); i++)
	{
		if (At(i) != other.At(i))
		{
			return false;
		}
	}
	return true;
}

bool String::operator!=(const String &other)
{
	return !(this == &other);
}

char String::At(int i) const
{
	return mInternalChars[i];
}
char String::operator[](int i) const
{
	return At(i);
}

std::size_t String::Size() const
{
	return mSizeOfString;
}

bool String::Empty() const
{
	return true;
}

std::ostream& operator<<(std::ostream& stream, String str)
{
	return stream;
}