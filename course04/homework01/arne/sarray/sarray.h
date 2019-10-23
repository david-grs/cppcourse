#pragma once
#include <array>

class sarray
{
public:
    static constexpr std::size_t MaxSize = 32;
    sarray() = default;
    void push_back(int element);
    int operator[](std::size_t index) const { return mData[index]; }
    int& operator[](std::size_t index) { return mData[index]; }
    int at(std::size_t index) const;
    int& at(std::size_t index);

private:
    std::size_t mSize = 0;
    std::array<int, MaxSize> mData;
};
