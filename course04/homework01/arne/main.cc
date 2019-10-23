#include <iostream>
#include "sarray/sarray.h"

int main()
{
    sarray a;
    a.push_back(1);
    a.push_back(10);
    a.push_back(-50);

    a.push_back(11);
    a.push_back(-110);
    a.push_back(2);

    std::cout << "sarray a=" << a[0] << std::endl;
    return 0;
}
