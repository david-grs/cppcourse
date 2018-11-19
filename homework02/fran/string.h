#pragma once
#include <memory>
#include <iostream>
#include <string>

class String
{
public:
	String();
	String(const size_t capacity);
	String(const char* data);
	String(const String& other);
	
	bool empty() const;
	
	size_t size() const;
	size_t capacity() const;
	char* c_str() const;
	
	String& operator=(String other);
	String& operator=(const std::string& data);
	
	String& operator+(const String& str);
	
	friend String operator+(const char* data, const String& other)
	{
		return String(data) + other;
	}
	
	bool operator==(const String& other) const;
	
	bool operator==(const char* data)
	{
		return String(data) == *this;
	}
	
	operator std::string() const
	{
		return std::string(c_str());
	};
	
	friend bool operator==(std::string data, const String& other)
	{
		return data == std::string(other);
	}
	
	friend bool operator==(const char* data, const String& other)
	{
		return String(data) == other;
	}
	
	char operator[](const int& i) const
	{
		return mData[i];
	}
	
	char& operator[](const int& i)
	{
		return mData[i];
	}
	
	friend std::ostream& operator<<(std::ostream& stream, const String& other)
	{
		stream << other.c_str();
		return stream;
	}

private:
	const size_t ZERO_SIZE = size_t(0);
	size_t mLength;
	size_t mCapacity;
	std::unique_ptr<char[]> mData;

	void resize();
};
