#include "ordered_array.h"

#include <algorithm>
#include <iostream>

OrderedArray::OrderedArray()=default;

OrderedArray::OrderedArray(const std::vector<int>& v):
mSize{v.size()}
{
    if (v.size() > MaxSize)
    {
        throw std::out_of_range("...");
    }

    std::copy(v.data(), v.data() + mSize, mData.data());
    std::sort(mData.data(), mData.data() + mSize);
}

OrderedArray::OrderedArray(size_t size, int value):
    mSize{size}
{
    if (size > MaxSize)
    {
        throw std::out_of_range("...");
    }

    for (size_t i = 0; i < mSize; i++)
        mData[i] = value;
}

void OrderedArray::push_back(int newElement)
{
    if (mSize >= MaxSize)
        throw std::out_of_range("...");

    mData[mSize] = newElement;
    std::sort(mData.data(), mData.data() + mSize);
}

std::ostream& operator<<(std::ostream& stream, const OrderedArray& orderedArray)
{
    const int* rowData = orderedArray.data();
    for (size_t i = 0; i < orderedArray.size(); i++)
        stream << rowData[i] << " ";

    return stream;
}
