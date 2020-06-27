#pragma once

#include <string>
#include <ostream>

class String
{
public:
    String();
    String(std::string&);
    bool Empty();
    std::size_t Size();
    

private:
    std::size_t mSize = 0;
    static const int mCapacity = 10;
    char mStream[mCapacity + 1];
};




