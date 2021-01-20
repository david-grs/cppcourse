#include "sortedarray.h"

#include <iostream>

int main()
{
	SortedArray testArray;

	// pushing back
	testArray.push_back(10);
	testArray.push_back(100);
	testArray.push_back(-10);
	testArray.push_back(0);

	for (size_t i = 0; i < testArray.size(); i++)
	{
		std::cout << testArray[i] << " ";
	}
	std::cout << std::endl;
}
