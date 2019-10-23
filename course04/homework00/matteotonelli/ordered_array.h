#pragma once

#include <vector>
#include <array>

class OrderedArray
{
public:
    static constexpr const std::size_t MaxSize = 40;

    OrderedArray();
    explicit OrderedArray(const std::vector<int>&);

    std::size_t size() const { return mSize; }
    std::size_t max_size() const { return MaxSize; }
    std::size_t capacity() const { return MaxSize; }

    int operator[](int idx) { return mData[idx]; }

    void push_back(int);

    const int* data() const { return mData.data(); }

private:
    std::size_t mSize = 0;
    std::array<int, MaxSize> mData;
};

std::ostream& operator<<(std::ostream& stream, const OrderedArray& orderedArray);
