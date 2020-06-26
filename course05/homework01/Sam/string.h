#pragma once

#include <string>
#include <ostream>

class String
{
public:
    String();
    String(std::string);

    bool Empty() const {return mSize==0;};
    std::size_t Size() const;

    // TODO
private:
    size_t mSize;
    int mCapacity;
    
};

std::ostream& operator<<(std::ostream& stream, String str)
{
    // TODO
    return stream;
}


