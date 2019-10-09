#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

class OrderedArray
{
public:
    static constexpr const std::size_t MaxSize = 1000;

    OrderedArray();
    OrderedArray(const std::vector<int>&);

    std::size_t size() const { return mSize; }
    std::size_t max_size() const { return MaxSize; }
    std::size_t capacity() const { return MaxSize; }

    void push_back(int);

    const int* c_array() const { return mData.data(); }

private:
    std::size_t mSize = 0;
    std::array<int, MaxSize> mData;
};

OrderedArray::OrderedArray()=default;

OrderedArray::OrderedArray(const std::vector<int>& v)
{
    if (v.size() <= MaxSize)
    {
        mSize = v.size();
    }
    else{
        throw std::out_of_range("Fermo!!! diocan!");
    }

    std::copy(v.data(), v.data() + mSize, mData.data());
    std::sort(mData.data(), mData.data() + mSize);
}

void OrderedArray::push_back(int newElement)
{
    if (mSize >= MaxSize)
        throw std::out_of_range("...");

    size_t i = 0;
    size_t j = mSize;
    while ((i < mSize) && (mData[i] < newElement))
        i++;

    while (j > i)
    {
        mData[j] = mData[j-1];
        --j;
    }
    mData[i] = newElement;
    ++mSize;
}



std::ostream& operator<<(std::ostream& stream, const OrderedArray& orderedArray)
{
    const int* rowData = orderedArray.c_array();
    for (size_t i = 0; i < orderedArray.size(); i++)
        stream << rowData[i] << " ";

    return stream;
}

class OrderedArrayVersion2
{
public:
    static constexpr const std::size_t MaxSize = 1000;

    OrderedArrayVersion2();
    OrderedArrayVersion2(const std::vector<int>&);

    std::size_t size() const { return mSize; }
    std::size_t max_size() const { return MaxSize; }
    std::size_t capacity() const { return MaxSize; }

    void push_back(int);

    const int* c_array() const { return mData.data(); }

    friend std::ostream& operator<<(std::ostream& stream, OrderedArrayVersion2& orderedArray)
    {
        if (orderedArray.mIsSorted)
        {
            std::sort(orderedArray.mData.data(), orderedArray.mData.data() + orderedArray.mSize);
            orderedArray.mIsSorted = true;
        }

        const int* rowData = orderedArray.c_array();
        for (size_t i = 0; i < orderedArray.size(); i++)
            stream << rowData[i] << " ";

        return stream;
    }

private:
    std::size_t mSize = 0;
    std::array<int, MaxSize> mData;
    bool mIsSorted = true;
};

OrderedArrayVersion2::OrderedArrayVersion2()=default;

OrderedArrayVersion2::OrderedArrayVersion2(const std::vector<int>& v)
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

void OrderedArrayVersion2::push_back(int newElement)
{
    if (mSize >= MaxSize)
        throw std::out_of_range("...");

    mData[mSize] = newElement;
    mIsSorted = false;
    ++mSize;
}

int main()
{
    OrderedArray s({1, 2, 9, 4});
    s.push_back(5);
    s.push_back(10);
    std::cout << s << std::endl;
    return 0;
}

