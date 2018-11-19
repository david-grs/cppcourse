#include "vector.h"

#include <iostream>

int main()
{
	vector v;

	for (std::size_t i = 0; i < 10; ++i)
	{
		std::cout << "capacity=" << v.capacity() << " size=" << v.size() << std::endl;
		v.push_back(i);
	}

	for (std::size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << std::endl;
	}

	vector v2 = v;
	for (std::size_t i = 0; i < v2.size(); ++i)
	{
		std::cout << v2[i] << std::endl;
	}

	vector v3 = v;
	v.push_back(10);

	v3 = v;
	return 0;
}
