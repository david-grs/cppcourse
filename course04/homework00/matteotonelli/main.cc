#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#include "ordered_array.h"

int main()
{
    OrderedArray s({1, 2, 9, 4});
    s.push_back(5);
    s.push_back(10);
    std::cout << s << std::endl;
    return 0;
}

