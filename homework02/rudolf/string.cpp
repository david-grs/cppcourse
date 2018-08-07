#include "string.h"

String::String():
		mString(nullptr),
		mSize(0),
		mCapacity(0)
{};
String::String(const char* chars,std::size_t capacity):
		mString(new char[capacity>strlen(chars)?capacity:strlen(chars)]),
		mSize(strlen(chars)),
		mCapacity(capacity>strlen(chars)?capacity:strlen(chars))
{
	std::copy_n(chars,mSize,mString.get());
};
String String::operator=(String str)
{
	std::swap(mString,str.mString);
	mSize =str.size();
	mCapacity =str.capacity();
	return *this;
}
String& String::operator+(const String& str)
{	
	String str2(c_str(),size()+str.size());
	for(std::size_t i=0;i<str.mSize; i++) 
	{		
		str2.push_back(str.mString[i]);
	}
	*this=str2;
	return *this;
}
void String::push_back(const char c)
{
	if (mSize==mCapacity)
		{add_capacity();}
	mString[mSize] = c;
	mSize+=1;
}
void String::add_capacity()
{
	std::unique_ptr<char[]> newString(new char[mCapacity*2 + 1]);
	std::copy_n(mString.get(),mSize,newString.get());
	mString=std::move(newString);
}

std::size_t strlen(const char* chars)
{
	std::size_t counter(0);
	while(chars[counter]){++counter;}
	return counter;
}

bool operator==(const std::string& str1,const String& str2)
{
	return str1==std::string(str2);
}

bool operator==(const char* chars,const String& str)
{
	return String(chars)==str;
};

String operator+(const char* chars, const String& str)
{
	return String(chars)+str;
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
	return  os << string.c_str();
};


