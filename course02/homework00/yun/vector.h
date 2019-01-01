#pragma once
#include <array>

class VectorInt
{
public:
	VectorInt();

	int size() const;

	int capacity() const;

	int back() const;
	int& back();

	void push_back(int);
	
	void clear();

private:
	int mSize;
	
	std::array<int, 42> mData;
};
