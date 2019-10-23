#include <array>
#include <algorithm>
#include <sarray.h>


void sarray::push_back(int element)
{
    if (mSize < MaxSize)
    {
        mData[mSize] = element;
        std::sort(mData.begin(), mData.begin() + mSize + 1);
        mSize += 1;
    }
    else
        throw std::runtime_error("max size exceeded");
}

int sarray::at(std::size_t index) const
{
    if (index < mSize)
        return mData[index];
    else
        throw std::out_of_range("index out of range");
}

int& sarray::at(std::size_t index)
{
    if (index < mSize)
        return mData[index];
    else
        throw std::out_of_range("index out of range");
}
