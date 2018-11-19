#pragma once

#include <memory>
#include <algorithm>

class vector
{
public:
	vector() :
		mData(nullptr),
		mCapacity(0),
		mSize(0)
	{}

	vector(const vector& other) :
		mData(std::make_unique<int[]>(other.mCapacity)),
		mCapacity(other.mCapacity),
		mSize(other.mSize)
	{
		std::copy_n(other.mData.get(), mSize, mData.get());
	}

	vector& operator=(vector other)
	{
		std::swap(mData, other.mData);
		std::swap(mCapacity, other.mCapacity);
		std::swap(mSize, other.mSize);
		return *this;
	}

	std::size_t capacity() const { return mCapacity; }
	std::size_t size() const { return mSize; }

	int operator[](std::size_t idx) const { return mData[idx]; }

	void push_back(int x)
	{
		if (mSize == mCapacity)
		{
			// full
			grow(mCapacity * 2 + 1);
		}

		mData[mSize] = x;
		++mSize;
	}

private:
	void grow(std::size_t newCapacity)
	{
		std::unique_ptr<int[]> newData
				= std::make_unique<int[]>(newCapacity);

		if (mData != nullptr)
		{
			std::copy_n(mData.get(), mSize, newData.get());
		}

		std::swap(mData, newData);
		mCapacity = newCapacity;
	}

	std::unique_ptr<int[]> mData;
	std::size_t mCapacity;
	std::size_t mSize;
};

