#pragma once

#include <string>
#include <ostream>
#include <istream>

class String
{
public:
	String();
	String(std::string);
	String(std::istream&);

	bool Empty() const;
	std::size_t Size() const;

	bool operator==(const String) const;
	bool operator!=(const String) const;

	String Substring(int start) const;
	String Substring(int start, int length) const;

	std::string str() const
	{
		return mString;
	}

private:
	std::string mString;
};

std::ostream& operator<<(std::ostream& stream, const String str);
