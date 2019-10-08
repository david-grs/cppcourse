#include "sarray.h"
#include <iostream>

int main()
{
	sarray a;
	a.push_back(3);
	a.push_back(1);
	a.push_back(5);
	a.push_back(2);
	a.push_back(4);
	a.push_back(6);
	a.push_back(0);

	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;
	std::cout << a[2] << std::endl;
	std::cout << a[3] << std::endl;
	std::cout << a[4] << std::endl;
	std::cout << a[5] << std::endl;
	std::cout << a[6] << std::endl;
	
	return 0;
}
