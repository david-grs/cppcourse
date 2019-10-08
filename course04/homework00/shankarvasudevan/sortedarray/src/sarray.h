#include <array>
#include <iostream>

class sarray
{
public:
	sarray();
		
	static constexpr const std::size_t MaxSize = 10;

	void push_back(int value) 
	{
		if (mLength == MaxSize)
		{
			throw std::out_of_range("Array is at max capacity");
		}

		mData[mLength++] = value;
		for (int i=mLength-1; i > 0 && mData[i] <= mData[i-1]; i--)
		{
			int tmp = mData[i];
			mData[i] = mData[i-1];
			mData[i-1] = tmp;
		}
	}

	int operator[](int index)
	{
		if (index < 0 || index >= MaxSize)
		{
			throw std::out_of_range("Invalid index specified");
		}
			
		return mData[index];
	} 

private:
	std::array<int, MaxSize> mData;
	int mLength; 
};

sarray::sarray()
{
	mLength = 0;
}
