#include "sarray.h"
#include <iostream>

int main()
{
	sarray a;
	a.push_back(1);
	a.push_back(10);
	a.push_back(-50);

	std::cout << a[0] << std::endl;

	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	sarray b{3};
	b.push_back(5);
	b.push_back(4);
	b.push_back(10);

	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
}
