#include "sorted_array.h"
#include <iostream>

SortedArray::SortedArray(std::size_t capacity) : mCapacity(capacity)
{
}

void SortedArray::clear() 
{
    mData.clear();
}

const std::size_t SortedArray::size()
{
    return mData.size();
} 

void SortedArray::push_back(size_t value)
{
    if (mData.size() == mCapacity)
    {
        throw std::out_of_range("Array is at maximum capacity");
    }

    mData.push_back(value);
    std::sort(mData.begin(), mData.end());
}

const std::size_t SortedArray::operator[](std::size_t index)
{
    return mData[index];
}

const std::size_t SortedArray::at(std::size_t index)
{
    if (index < 0 || index >= mData.size())
    {
        throw std::out_of_range("Invalid index specified");
    }

    return mData[index];
}


