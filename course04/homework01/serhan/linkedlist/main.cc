#include "linked_list.h"
#include <iostream>
#include <vector>

int main() {
	linked_list list;

	std::vector<int> v = {1,2,3,4,5};

	std::cout << "size before fill: " << list.size() << std::endl;

	for (int x : v)
		list.push_front(x);

	std::cout << list << std::endl;

	std::cout << "size after fill: " << list.size() << std::endl;
	std::cout << "item at beginning: " << list.getHead() << std::endl;

	list.pop_front();

	std::cout << list << std::endl;
	std::cout << "size after pop: " << list.size() << std::endl;
	std::cout << "item at beginning: " << list.getHead() << std::endl;

	list.reverse();

	std::cout << list << std::endl;
	std::cout << "size after reverse: " << list.size() << std::endl;
	std::cout << "item at beginning: " << list.getHead() << std::endl;

	list.reset();

	std::cout << "size after clear: " << list.size() << std::endl;
}