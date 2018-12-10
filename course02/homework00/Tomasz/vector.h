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
		_size(0)
	{ }

	size_t capacity() const
	{
		return _data.size();
	}

	size_t size() const
	{
		return _size;
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

		_data[_size++] = value;
	}

	int front() const
	{
		if (empty())
			throw std::out_of_range("VectorInt is empty");

		return _data[0];
	}

	int& front() {
		if (empty())
			throw std::out_of_range("VectorInt is empty");

		return _data[0];
	}

	int back() const
	{
		if (empty())
			throw std::out_of_range("VectorInt is empty");

		return _data[_size - 1];
	}

	int& back() {
		if (empty())
			throw std::out_of_range("VectorInt is empty");

		return _data[_size - 1];
	}

	int operator[](std::size_t index) const
	{
		return _data[index];
	}

	int& operator[](std::size_t index)
	{
		return _data[index];
	}

	int at(std::size_t index) const
	{
		if (!in_range(index))
			throw std::out_of_range("VectorInt index out of range");

		return _data[index];
	}

	int& at(std::size_t index)
	{
		if (!in_range(index))
			throw std::out_of_range("VectorInt index out of range");

		return _data[index];
	}

	DataType::iterator begin()
	{
		return _data.begin();
	}

	DataType::const_iterator begin() const
	{
		return _data.begin();
	}

	DataType::iterator end()
	{
		return _data.begin() + _size;
	}

	DataType::const_iterator end() const
	{
		return _data.begin() + _size;
	}

	void clear()
	{
		_size = 0;
	}
	
private:

	bool in_range(size_t index) const
	{
		return index < _size;
	}

	std::size_t _size;
	DataType _data;
};


