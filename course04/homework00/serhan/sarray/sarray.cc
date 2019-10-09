#include "sarray.h"

sarray::sarray(size_t maxSize) :
        mCapacity{maxSize}
{
}

sarray::sarray()
{
    mCapacity = 32;
}

void sarray::push_back(int element)
{
    if (size() + 1 > capacity())
        throw std::out_of_range("Array out of bounds");
    mData.push_back(element);
    std::sort(mData.begin(), mData.end());
}

size_t sarray::size() const
{
    return mData.size();
}

size_t sarray::capacity() const
{
    return mCapacity;
}

int sarray::operator[](size_t i) const
{
    return mData[i];
}

ostream & operator << (ostream &out, const sarray &s)
{
    for (int i = 0; i < s.size(); i++)
        out << s[i] << " ";
    out << endl;
    return out;
}
