#pragma once

#include <iostream>

struct Integer
{
    int mValue;

    Integer(int value) :
        mValue{value}
    {}
};

class UniquePtrInt
{
public:
    UniquePtrInt():
        mInteger{nullptr}
    {}
    ~UniquePtrInt();
    operator int() const { return mInteger->mValue;}
    explicit UniquePtrInt(int value){ mInteger = new Integer(value);}
    int get() const { return mInteger->mValue; }
    void give_ownership_to(UniquePtrInt& newPtr);

private:
    Integer * mInteger = nullptr;

};

std::ostream& operator<<(std::ostream& stream, const UniquePtrInt&);
