#include "string.h"
#include <string>


String::String(){};

String::String(std::string str)
{
    if (str.size() > mSize)
    {
        throw "str is larger than String size!";
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        mStream[i] = str[i];
    }
};

bool String::Empty()
{
    return mSize==0;
};

std::size_t String::Size() 
{
    return mSize;
};

std::ostream& operator<<(std::ostream& stream, String str)
{
    return stream;
}
