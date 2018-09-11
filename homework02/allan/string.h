
#pragma once

#include <iosfwd>
#include <memory>

class String
{
public:
    String();
    String(const char *);
    String(const String& other);
                String(const char *, int capactiy);
    String& operator=(String other);
    ~String();

    bool empty() const;
    const char* c_str() const ;

    operator std::string() const;

    char& operator[](int pos);
    const char& operator[](int pos) const;

    int size() const;
    int capacity() const;

private:

    int mCapacity;
    std::unique_ptr<char[]> mData;
};

std::ostream& operator<<(std::ostream& ostr, const String& str);

String operator+(const char *lhs, const String& rhs);

bool operator==(const char *lhs, String rhs);
bool operator==(String lhs, const char *rhs);
bool operator==(const std::string lhs, const String rhs);

