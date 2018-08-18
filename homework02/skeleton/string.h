#include <iostream>
#include <memory>


#pragma once

class String
{
public:
    String();
    String(const String&);
    String(const char*);

    bool empty() const;
    int size() const;
    int capacity() const;
    char* c_str() const;

    char& operator[](int) const;
    operator std::string () const;

private:
    std::unique_ptr<char[]> mCharacters;
    int mSize;
    int mCapacity;
};

std::ostream& operator<<(std::ostream&, const String&);
String operator+(const char*, const String&);
bool operator==(const char*, String);
bool operator==(std::string, String);
