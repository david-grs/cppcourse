#pragma once
#include <array>


class VectorInt
{
public:
	int capacity() const;
	int size() const;
	int back() const;
	int& back();
	void push_back(int) ;
	void clear();	
private:
	static const int mMaxSize = 256;
	std::array<int, mMaxSize> mData;
	int mSize = 0;
};


