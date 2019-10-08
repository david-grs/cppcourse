#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

class SortedArray
{
public:
	SortedArray(std::size_t maxSize);
	void push_back(int element);
	int operator[](std::size_t index);
	int at(std::size_t index);
	bool empty();
	std::size_t size();
	std::size_t max_size();
	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();
private:
	std::size_t mMaxSize;
	std::vector<int> mVector;
};
