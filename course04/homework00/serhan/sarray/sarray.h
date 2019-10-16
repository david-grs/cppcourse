#pragma once

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class sarray
{

public:
    explicit sarray(size_t maxSize);
    sarray();
    void push_back(int element);
    size_t size() const;
    size_t capacity() const;
    int operator[](size_t i) const;
    friend ostream & operator << (ostream &out, const sarray &s);

private:
    size_t mCapacity;
    std::vector<int> mData;

};