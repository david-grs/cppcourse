#pragma once

class VectorInt
{
public:
	int capacity() const;
	int size() const;
	int back() const;
	void push_back(const int&) ;
	void clear();	
private:
	static const int mMaxSize = 256;
	int mData[mMaxSize];
	int mSize = 0;
};


