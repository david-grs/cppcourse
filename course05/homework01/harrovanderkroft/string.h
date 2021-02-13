#pragma once


#include <stdexcept>
#include <ostream>
#include <string>
#include <cstring>
#include <array>

class String
{
private:
    static constexpr int MAX_STRING_SIZE = 1024;
	std::array<char, MAX_STRING_SIZE> mInternalChars;
    std::size_t mSizeOfString;
public:
	String();
	String(std::string strInput);
	String(char const* mInternalChars);
    void ParseChar(const char mInternalChars[]); 
    char CharAt(int i);
    String operator+=(String other);
    String operator+(String other);
    bool operator!=(String other);
    bool operator==(String other);
    char At(int i) const;
    char operator[](int i) const;
    std::size_t Size() const;
	bool Empty() const;
};

