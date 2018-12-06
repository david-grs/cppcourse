#pragma once

#include <array>
#include <exception>

struct RanOutOfMemoryException : public std::exception
{
};

class VectorInt
{
public:
	size_t size() const
	{
		return mSize;
	}

	size_t capacity() const
	{
		return mMemory.max_size();
	}

	void push_back(const int& element)
	{
		if (size() >= mAllocatedMemory)
		{
			mAllocatedMemory *= 2;
			if (mAllocatedMemory > capacity())
			{
				throw RanOutOfMemoryException();
			}
		}
		mMemory.at(size()) = element;
		mSize += 1;
	}

	int& back()
	{
		if (size() > 0)
			return mMemory.at(size() - 1);
		else
			throw std::out_of_range("Our vector is empty so there is no last value");
	}

	void clear()
	{
		mSize = 0;
	}

	int& at(const size_t& position)
	{
		if (position < size())
			return mMemory.at(position);
		else
			throw std::out_of_range("Accessed element out of bounds");
	}

private:
	std::array<int, 1024> mMemory;
	size_t mAllocatedMemory = 8;
	size_t mSize = 0;
};




