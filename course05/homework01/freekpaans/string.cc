#include "string.h"

String::String()
	: String{""}
{
}

String::String(std::string s)
	: mString{s}
{
}

String::String(std::istream& is)
{
	// I want to keep String immutable, that doesn't seem compatible with the notion semantics of istream >> str. So now
	// I create it using a constructor, but I think it would be better to use a function for this, but where to put it?
	// Make it a static of String? Or in the global namespace? Neither seem ideal.
	is >> mString;
}

bool String::Empty() const
{
	return Size()==0;
}

std::size_t String::Size() const
{
	return mString.size();
}

std::ostream& operator<<(std::ostream& stream, const String str)
{
	stream << str.str();

	return stream;
}

bool String::operator==(const String b) const
{
	return mString == b.mString;
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
	return String{mString.substr(start, len)};
}
