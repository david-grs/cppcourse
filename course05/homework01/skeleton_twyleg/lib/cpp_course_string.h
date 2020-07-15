// Some copyright 2020
#pragma once

#include <iosfwd>
#include <string>
#include <array>

namespace cppcourse {

class String
{
public:
	String();
	String(const std::string&);

	bool Empty() const { return (mSize == 0); };
	std::size_t Size() const { return mSize; };
	const char* c_str() const { return mData.data(); };
	String& append(const String&);

	bool operator==(const String& rhs) const;
	bool operator!=(const String& rhs) const;

	friend std::ostream& operator<<(std::ostream& stream, String str);
	constexpr static size_t STRING_MAX_LENGTH = 512;

private:

	size_t mSize;
	std::array<char, STRING_MAX_LENGTH> mData;

};

}

