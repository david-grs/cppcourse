#pragma once

#include <cstring>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

class String
{
public:
	String(const char s[]) : mSize(std::strlen(s)), mContents(std::make_unique<char[]>(mSize))
	{
		std::strcpy(mContents.get(), s);
	}
	String() : String("") {}
	String(const std::string s) : String(s.c_str()) {}
	String(const String &s) : String(s.c_str()) {}

	const bool Empty() const { return mSize == 0; };
	const std::size_t Size() const { return mSize; };
	const char *c_str() const { return mContents.get(); };

	// mainly added these two to help with testing operator+
	const bool StartsWith(const String substr) const
	{
		return (std::strncmp(c_str(), substr.c_str(), substr.Size()) == 0);
	}

	const bool EndsWith(const String substr) const
	{
		// First, find the substring
		const char *found_sub = std::strstr(c_str(), substr.c_str());
		if (found_sub == NULL)
		{
			// If it's not there, we're done
			return false;
		}
		// else, compare the found sub to the given one.
		// do not use strncmp here, because if the found substr is longer than the given one it should be
		// false
		return std::strcmp(found_sub, substr.c_str()) == 0;
	}

private:
	const std::size_t mSize;
	const std::unique_ptr<char[]> mContents;
};

std::ostream &operator<<(std::ostream &stream, const String &str)
{
	stream << str.c_str();
	return stream;
}

const bool operator==(const String &str1, const String &str2) { return std::strcmp(str1.c_str(), str2.c_str()) == 0; }

const bool operator!=(const String &str1, const String &str2) { return !(str1 == str2); }

const String operator+(const String &str1, const String &str2)
{
	char tmpstr[str1.Size() + str2.Size()];
	std::strcpy(tmpstr, str1.c_str());
	std::strcat(tmpstr, str2.c_str());
	return String(tmpstr);
}
