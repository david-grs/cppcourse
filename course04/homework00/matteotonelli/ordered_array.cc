#include "ordered_array.h"

#include <algorithm>
#include <iostream>

OrderedArray::OrderedArray()=default;

OrderedArray::OrderedArray(const std::vector<int>& v)
{
    if (v.size() <= MaxSize)
    {
        mSize = v.size();
    }
    else{
        throw std::out_of_range("...");
    }

    std::copy(v.data(), v.data() + mSize, mData.data());
    std::sort(mData.data(), mData.data() + mSize);
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
