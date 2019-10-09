#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class sarray
{
public:
    static constexpr const std::size_t MaxSize = 32;

    sarray() = default;

    void push_back(int element)
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

    int operator[](std::size_t index)
    {
        if (index < mSize)
            return mData[index];
        else
            throw std::runtime_error("index out of range");
    }

private:
    std::size_t mSize = 0;
    std::array<int, MaxSize> mData;
};



int main()
{
    sarray a;
    a.push_back(1);
    a.push_back(10);
    a.push_back(-50);

    a.push_back(11);
    a.push_back(-110);
    a.push_back(2);

    cout << "sarray a=" << a[0] << endl;
    return 0;
}
