#pragma once
#include <iostream>
#include <memory>
#include <algorithm>

std::size_t strlen(const char* chars);

class String
{
public:
	String();

	String(const char* chars,std::size_t capacity);

	String(const char* chars):String(chars,strlen(chars)){};
	
	String(const String& str):String(str.c_str()){};
	
	String operator=(String str);
	
	const bool empty()const {return mSize==0;}

	char& operator[](int idx)const { return mString[idx];}

	bool operator==(const String& str)const{return std::equal(c_str() , c_str() + mSize , str.c_str());};

	String& operator+(const String& str);
	
	operator std::string()const{return c_str();}

	void push_back(const char c);
	void add_capacity();

	std::size_t size()const{return mSize;};
	std::size_t capacity()const{return mCapacity;};

	const char* c_str()const {return mString.get();}
private:
	std::unique_ptr<char[]> mString;
	std::size_t mSize;
	std::size_t mCapacity;
};


bool operator==(const std::string& str1,const String& str2);

bool operator==(const char* chars,const String& str);

String operator+(const char* , const String& str);

std::ostream& operator<<(std::ostream&, const String&);
