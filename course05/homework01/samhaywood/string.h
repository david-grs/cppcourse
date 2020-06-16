#pragma once

#include <string>
#include <ostream>

class String
{
public:
    String();
    String(std::string);

    bool Empty() const;
    std::size_t Size() const;

    // TODO
};

std::ostream& operator<<(std::ostream& stream, String str)
{
    // TODO
    return stream;
}


