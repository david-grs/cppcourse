#pragma once

class UniquePtrInt
{
public:
    ~UniquePtrInt() {delete(mValue);}
    static UniquePtrInt make_unique_int(int);
    operator int() const { return mValue*;}

private:
    int * mValue;
    explicit UniquePtrInt(int value){ mValue = new int{value};}

};

std::ostream& operator<<(std::ostream& stream, const UniquePtrInt&);
