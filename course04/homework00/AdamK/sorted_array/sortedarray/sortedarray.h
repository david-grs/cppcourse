#pragma once

#include <array>

class SortedArray
{
public:
	static constexpr const std::size_t MaxSize = 32;

	void push_back(int element);

	int operator[](std::size_t index) const { return mArray[index]; };
	int at(std::size_t index) const { return mArray.at(index); };

	std::size_t size() const { return mSize; };
	std::size_t max_size() const { return mArray.max_size(); };

private:
	std::size_t mSize = 0;
	std::array<int, MaxSize> mArray;
};
