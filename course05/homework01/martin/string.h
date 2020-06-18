#pragma once

#include <string>
#include <ostream>
#include <iostream>

class String
{
public:
	String();
	String(std::string);


        bool Empty() const;
        std::size_t Size() const;
        int SetString(std::string str);
        std::string GetString() const;

private:
        std::string mStr;

};

String::String()
{
    std::cout << "String has been initialized" << std::endl;
}

bool String::Empty() const
{
    return mStr.empty();
}

int String::SetString(std::string str)
{
    mStr = str;
    std::cout << mStr << std::endl;
    return 0;
}

std::string String::GetString() const
{
    return mStr;
}


std::ostream& operator<<(std::ostream& stream, String str)
{
	// TODO
	return stream;
}

