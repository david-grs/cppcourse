#include "sorted_array.h"
#include <iostream>

int main()
{
	std::cout << "Initialising SortedArray with capacity: 3" << std::endl;
	SortedArray sortedArray(3);

	std::cout << "Inserting values into SortedArray: 3, 2, 1" << std::endl;
	sortedArray.Insert(3);
	sortedArray.Insert(2);
	sortedArray.Insert(1);

	std::cout << "SortedArray: {";
	std::cout << sortedArray[0] << ", ";
	std::cout << sortedArray[1] << ", ";
	std::cout << sortedArray[2];
	std::cout << "}" << std::endl;
}
