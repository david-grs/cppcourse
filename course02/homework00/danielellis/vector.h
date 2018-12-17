#pragma once

#include <array>
#include <exception>

class VectorInt
{
public:
	std::size_t size() const
	{
		return mSize;
	}

	std::size_t capacity() const
	{
		return mMemory.max_size();
	}

	void push_back(const int element)
	{
		if (size() >= mAllocatedMemory)
		{
			mAllocatedMemory *= 2;
			if (mAllocatedMemory > capacity())
				throw std::runtime_error("Ran out of memory");
		}
		mMemory[size()] = element;
		mSize += 1;
	}

	int& back()
	{
		if (size() <= 0)
			throw std::out_of_range("Our vector is empty so there is no last value");
		else
			return mMemory[size() - 1];
	}

	int back() const
	{
		if (size() <= 0)
			throw std::out_of_range("Our vector is empty so there is no last value");
		else
			return mMemory[size() - 1];
	}

	void clear()
	{
		mSize = 0;
	}

	int& at(const std::size_t position)
	{
		if (position < size())
			return mMemory.at(position);
		else
			throw std::out_of_range("Accessed element out of bounds");
	}

	int at(const std::size_t position) const
	{
		if (position < size())
			return mMemory.at(position);
		else
			throw std::out_of_range("Accessed element out of bounds");
	}

private:
	std::array<int, 1024> mMemory;
	std::size_t mAllocatedMemory = 8;
	std::size_t mSize = 0;
};
