#include <iostream>
#include <memory>
#include <algorithm>
#include <cstdlib>

class VectorInt
{
public:
	VectorInt() :
		mSize(0),
		mCapacity(0)
	{}

	VectorInt(const VectorInt& other) :
		mData(std::make_unique<int[]>(other.size())),
		mSize(0),
		mCapacity(other.size())
	{
		for (int i = 0; i < other.size(); ++i)
		{
			push_back(other[i]);
		}
	}

	VectorInt& operator=(VectorInt other)
	{
		std::swap(mData, other.mData);
		std::swap(mSize, other.mSize);
		std::swap(mCapacity, other.mCapacity);
		return *this;
	}

	void push_back(int value)
	{
		if (size() == capacity())
		{
			grow();
		}

		mData[mSize] = value;
		++mSize;
	}

	int size() const { return mSize; }
	int capacity() const { return mCapacity; }

	int operator[](std::size_t n) const
	{
		return mData[n];
	}

private:
	void grow()
	{
		const int newCapacity = capacity() * 2 + 1;

		auto newData = std::make_unique<int[]>(newCapacity);
		if (mData)
		{
			std::copy_n(mData.get(), mSize, newData.get());
		}

		mCapacity = newCapacity;
		mData = std::move(newData);
	}

	std::unique_ptr<int[]> mData;
	int mSize;
	int mCapacity;
};


int main()
{
	VectorInt vi;
	for (int i = 0; i < 10; ++i)
	{
		vi.push_back(i);
	}

	std::cout << "FOO " << std::endl;

	VectorInt vi2;
	vi2 = vi;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << vi2[i] << std::endl;
	}

	return 0;
}



