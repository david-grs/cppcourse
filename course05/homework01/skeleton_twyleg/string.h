// Some copyright 2020

#pragma once

#include <string>
#include <ostream>
#include <array>
#include <cstring>

namespace cppcourse {

class String
{
public:
	String();
    String(std::string);

    bool Empty() const { return (mSize == 0); };
    std::size_t Size() const { return mSize; };
    const char* c_str() const { return mData.data(); };
    String& append(const String&);


    friend std::ostream& operator<<(std::ostream& stream, String str);
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);

    constexpr static size_t STRING_MAX_LENGTH = 512;

private:

    size_t mSize;
    std::array<char, STRING_MAX_LENGTH> mData;

};

std::ostream& operator<<(std::ostream& stream, String str);
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);

}
