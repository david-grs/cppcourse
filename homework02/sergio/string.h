#pragma once
#include <iosfwd>
#include <memory>

class String
{
public:
	String();
	String(const char*);
	String(const String&);
	
	size_t size() const { return mSize; };
	size_t capacity() const { return mCapacity; };
	bool empty() const { return String::size() == 0; };
	char* c_str() const { return mData.get(); }
	
	String& operator= (const char*);
	String& operator= (String);
	
	char& operator[] (size_t);
	char operator[] (size_t) const;
	
	bool operator== (const String&) const;

	String operator+ (const String&) const;
	
	operator std::string() const { return std::string(c_str()); };
  
private:
	size_t mSize{0};
	size_t mCapacity{0};
	std::unique_ptr<char[]> mData{nullptr};
};
