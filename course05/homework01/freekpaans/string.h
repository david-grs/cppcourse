#pragma once

#include <string>
#include <ostream>
#include <istream>

class String
{
public:
	String();
	String(std::string);

	bool Empty() const;
	std::size_t Size() const;

	bool operator==(const String) const; // These two copy the comparand, but we didn't cover references yet, right :)
	bool operator!=(const String) const;

	String Substring(int start) const;
	String Substring(int start, int length) const;

	const char* begin() const
	{
		return mChars;
	}

	const char* end() const
	{
		return mChars+mSize;
	}

	const static int MaxChars = 256;

private:
	String(const char* b, const char* e);
	size_t mSize{};
	char mChars[MaxChars];
};

std::ostream& operator<<(std::ostream& stream, const String str);
String StringFromIstream(std::istream& stream); // With an immutable String, where do we put this one (we can't use
												// operator>>(istream) as that requires a mutable String. What is the
												// idiomatic way to handle this? (Don't say no immutables...)
