#pragma once

#include <algorithm>
#include <vector>

class sarray
{

public:
	sarray();
	explicit sarray(size_t maxSize);
	void push_back(int element);
	size_t size() const { return mData.size(); }
	size_t capacity() const { return mCapacity; }
	int& operator[](size_t i);

private:
	size_t mCapacity;
	std::vector<int> mData;

};