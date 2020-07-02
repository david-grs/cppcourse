#include "string.h"

#include <algorithm>
#include <stdexcept>

String::String()
{
}

String::String(std::string s)
{
	if(s.size() > MaxChars)
	{
		throw std::runtime_error{"String too long: " + s};
	}

	mSize = s.size();
	copy(s.begin(), s.end(), mChars);
}

String::String(const char* b, const char* e)
	: mSize{static_cast<size_t>(e - b)}
{
	// Note that this is a private constructor; maintaining the invariant is the responsibility of the methods.
	std::copy(b, e, mChars);
}

bool String::Empty() const
{
	return Size()==0;
}

std::size_t String::Size() const
{
	return mSize;
}

std::ostream& operator<<(std::ostream& stream, const String str)
{
	copy(str.begin(), str.end(), std::ostreambuf_iterator<char>{stream});

	return stream;
}

bool String::operator==(const String b) const
{
	if(mSize != b.mSize)
	{
		return false;
	}

	return std::equal(begin(), end(), b.begin());
}

bool String::operator!=(const String b) const
{
	return !(*this == b);
}

String String::Substring(int start) const
{
	return Substring(start, Size()-start);
}

String String::Substring(int start, int len) const
{
	// TODO: handle start/len bounds
	return String{mChars+start, mChars+start+len};
}

String StringFromIstream(std::istream& istream)
{
	std::string s;
	istream >> s;
	return String{s};
}
