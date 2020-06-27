#include "string.h"
#include <string>


String::String(){};

String::String(const std::string& str)
{
    if (str.size() > mCapacity)
    {
        throw std::runtime_error("str is larger than String capacity!");
    }
    
    for (std::size_t i = 0; i < str.size(); i++)
    {
        mStream[i] = str[i];
    }
    
    mSize = str.size();
};

bool String::Empty()
{
    return mSize==0;
};

std::size_t String::Size() 
{
    return mSize;
};

//std::ostream& operator<<(std::ostream& stream, String str)
//{
//    return stream;
//}
