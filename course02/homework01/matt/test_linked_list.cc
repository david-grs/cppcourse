#include <iostream>
#include "linked_list.h"
#include <algorithm>

int main()
{
	LinkedList<int> l;
	l.Append(1);
	l.Append(2);
	l.Append(3);

	std::cout << "l: " << l << std::endl;

	LinkedList<int> lCopyConstructed(l);
	std::cout << "lCopyConstructed: " << lCopyConstructed << std::endl;
	
	LinkedList<int> lAssigned;
	lAssigned = l;
	std::cout << "lAssigned: " << lAssigned << std::endl;

	std::cout << "iterator: ";
	for(auto i: l)
	std::cout << i << ", ";
	std::cout << std::endl;
 
    std::cout << "algorithm: ";
	std::for_each(l.begin(), l.end(), [](int& i) { std::cout << i << ", " ; });
	std::cout << std::endl;

	return 0;
}
