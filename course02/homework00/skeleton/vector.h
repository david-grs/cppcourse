#pragma once

#include <array>

class VectorInt
{
	
public:
	int32_t size()
	{
		return mSize;
	}

	int32_t capacity()
	{
		return mData.size();
	}

	int32_t back()
	{
		if (mSize > 0)		
			return mData[mSize-1];
	}

	void push_back(int32_t member)
	{

		if (mSize < mData.size())
		{
			mData[mSize] = member;
			++mSize;
		}
	}

	void clear()
	{
		mSize = 0;
	}

private:
	int32_t mSize{0};
	std::array<int32_t, 128> mData;
};


