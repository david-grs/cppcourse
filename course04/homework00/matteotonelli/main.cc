#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#include "ordered_array.h"
#include "unique_ptr_int.h"

int main()
{
    UniquePtrInt ptr{9};
    std::cout << ptr << std::endl;
    UniquePtrInt ptr2;
    ptr.give_ownership_to(ptr2);
    std::cout << ptr2 << std::endl;
    return 0;
}

