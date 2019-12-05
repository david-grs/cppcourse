#pragma once

#define _GLIBCXX_DEBUG 1
#include <array>

class SortedArray
{
public:
	static constexpr std::size_t MaxSize = 16;

	SortedArray() =default;
	explicit SortedArray(std::size_t size, int value = {});

	void push_back(int);

	int operator[](std::size_t i) const { return mData[i]; }
	int& operator[](std::size_t i) { return mData[i]; }

	int at(std::size_t i) const { return mData.at(i); }
	int& at(std::size_t i) { return mData.at(i); }

	bool empty() const { return mSize == 0; }
	std::size_t size() const { return mSize; }
	std::size_t max_size() const { return MaxSize; }
	std::size_t capacity() const { return MaxSize; }

private:
	std::size_t mSize = 0;
	std::array<int, MaxSize> mData;
};

inline SortedArray::SortedArray(std::size_t size, int value) :
	mSize{size}
{
	std::fill(mData.begin(), mData.begin() + mSize, value);
}
