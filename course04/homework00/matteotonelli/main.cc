#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#include "ordered_array.h"
#include "unique_ptr_int.h"

int main()
{
    UniquePtrInt ptr = UniquePtrInt::make_unique_int(9);
    std::cout << ptr << std::endl;
    return 0;
}

