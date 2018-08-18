#pragma once
#include <iosfwd>
#include <memory>

class String
{
public:
	String();

	String(const char* chars, std::size_t capacity);

	String(const char* chars);
	
	String(const String& str):String( str.c_str() ){}
	
	String operator=(String str);
	
	const bool empty() const { return mSize==0; }

	const bool operator==(const String& str) const;

	char& operator[](const int idx) const { return mString[idx]; }

	const char* c_str() const {return mString.get();}
	
	std::size_t size() const { return mSize; }
	std::size_t capacity() const { return mCapacity; }

	operator std::string() const { return c_str(); }

	String& operator+(const String& str);
	
	void push_back(const char c);
	void add_capacity();


private:
	std::size_t mSize;
	std::size_t mCapacity;
	std::unique_ptr<char[]> mString;
};


bool operator==(const std::string& str1,const String& str2);

bool operator==(const char* chars, const String& str);

String operator+(const char* chars, const String& str);

std::ostream& operator<<(std::ostream&, const String&);
