#include "sortedarray.h"

#include <iostream>

int main()
{
	SortedArray testArray{10};

	// pushing back
	testArray.push_back(10);
	testArray.push_back(100);
	testArray.push_back(-10);
	testArray.push_back(0);

	for (const auto& x : testArray)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// exceeding max size
	for (int i = -5; i < 5; ++i)
	{
		try
		{
			testArray.push_back(i);
		}
		catch (const std::exception& exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}

	for (const auto& x : testArray)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
