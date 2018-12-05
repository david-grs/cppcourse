#pragma once
#include <array>
#include <stdexcept>

class VectorInt
{
	public:
		VectorInt():
			mSize(0)
		{}
		
		int size() const
		{
			return mSize;
		}

		int capacity() const
		{
			return mData.size();
		}

		void push_back(int value)
		{
			if(mSize == mData.size()){
				throw std::out_of_range("vector at capacity");
			}
			mData[mSize++] = value;
		}

		int back(){
			if(mSize == 0){
				throw std::out_of_range("vector is empty");
			}
			return mData.at(--mSize);
		}

		void clear(){
			// no need to overwrite data
			mSize = 0;
		}

	private:
		std::array<int, 10> mData;
		std::size_t mSize; // how many items are in the vector
};


