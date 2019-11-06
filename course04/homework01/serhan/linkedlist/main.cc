#include "linked_list.h"
#include <iostream>

int main() {
	linked_list list;

	list.push_front(5);
	list.push_front(2);
	list.push_front(14);
	list.push_front(8);
	list.push_front(11);
	std::cout << list << std::endl;

	list.pop_front();
	std::cout << list << std::endl;

	std::cout << list.at(0) << std::endl;
}