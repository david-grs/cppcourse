#include "sarray.h"

int main()
{
    sarray a;
    a.push_back(1);
    a.push_back(10);
    a.push_back(-50);

    std::cout << a[0] << std::endl;
    cout << a;


    sarray b{3};
    b.push_back(5);
    b.push_back(4);
    b.push_back(10);
    cout << b;
}
