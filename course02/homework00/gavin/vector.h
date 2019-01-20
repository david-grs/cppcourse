#pragma once
#include <array>

class VectorInt
{
public:
	VectorInt();

	void push_back(int element);

	std::size_t size() const;

    std::size_t capacity();

	int& back();
	int back() const;

	void clear();

	int& at(std::size_t  index);
	int at(std::size_t  index) const;

private:
    std::array<int, 128> mData;
    size_t mSize;
};


