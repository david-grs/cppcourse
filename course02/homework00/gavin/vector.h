#pragma once
#include <array>
class VectorInt
{
public:
	VectorInt();

	void push_back(int element);

	size_t size();

	size_t capacity();

	int& back();

	void clear();

	int& at(size_t index);

private:
    std::array<int, 128> mData;
    size_t mSize;
};


