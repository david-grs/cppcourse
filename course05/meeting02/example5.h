#include <iostream>


// 1- dont mix signed / unsigned
// 2- (int) "C-style cast" -> boost::numeric_cast

void example5()
{
	int i = -1;
	unsigned j = 1;

	if (i < (int)j)
		std::cout << "-1 < 1" << std::endl;
	else
		std::cout << "-1 >= 1" << std::endl;
}
