#include "string.h"

String::String()
	: String{ "" }
{
}

String::String(std::string s)
	: mString{ s }
{
}

String::String(std::istream&)

{
}


bool String::Empty() const
{
	return Size() == 0;
}

std::size_t String::Size() const
{
	return mString.size();
}


bool String::operator==(const String x) const
{
	return mString == x.mString;
}


bool String::operator!=(const String x) const
{
	return mString != x.mString;
}


String String::Substring(int start) const
{
	return mString.substr(start);
}


String String::Substring(int start, int end) const
{
	return mString.substr(start, end);
}

std::ostream& operator<<(std::ostream& stream, const String str)
{
	stream << str.str();

	return stream;
}

