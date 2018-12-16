#pragma once

#include <array>
#include <stdexcept>
#include <iterator>

class VectorInt
{
private:
	using DataType = std::array<int, 100>;

public:
	VectorInt() :
		mSize(0)
	{ }

	std::size_t capacity() const
	{
		return mData.size();
	}

	std::size_t size() const
	{
		return mSize;
	}

	bool empty() const
	{
		return size() == 0;
	}

	bool full() const
	{
		return size() >= capacity();
	}

	void push_back(int value)
	{
		if (full())
			throw std::out_of_range("VectorInt is already full");

		mData[mSize++] = value;
	}

	int front() const
	{
		if (empty())
			throw std::out_of_range("VectorInt is empty");

		return mData[0];
	}

	int& front() {
		if (empty())
			throw std::out_of_range("VectorInt is empty");

		return mData[0];
	}

	int back() const
	{
		if (empty())
			throw std::out_of_range("VectorInt is empty");

		return mData[mSize - 1];
	}

	int& back() {
		if (empty())
			throw std::out_of_range("VectorInt is empty");

		return mData[mSize - 1];
	}

	int operator[](std::size_t index) const
	{
		return mData[index];
	}

	int& operator[](std::size_t index)
	{
		return mData[index];
	}

	int at(std::size_t index) const
	{
		if (!in_range(index))
			throw std::out_of_range("VectorInt index out of range");

		return mData[index];
	}

	int& at(std::size_t index)
	{
		if (!in_range(index))
			throw std::out_of_range("VectorInt index out of range");

		return mData[index];
	}

	DataType::iterator begin()
	{
		return mData.begin();
	}

	DataType::const_iterator begin() const
	{
		return mData.begin();
	}

	DataType::const_iterator cbegin() const
	{
		return mData.cbegin();
	}

	DataType::iterator end()
	{
		return mData.begin() + mSize;
	}

	DataType::const_iterator end() const
	{
		return mData.begin() + mSize;
	}

	DataType::const_iterator cedn() const
	{
		return mData.cend();
	}

	void clear()
	{
		mSize = 0;
	}
	
private:

	bool in_range(size_t index) const
	{
		return index < mSize;
	}

	std::size_t mSize;
	DataType mData;
};


