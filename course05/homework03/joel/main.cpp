#include "main.hpp"
#include <ostream>

int main()
{
	Node<std::string> n2{"this is a test"};
	if (n2.mData)
		std::cout << *n2.mData << std::endl;

	auto n3 = n2.Append("This is another test");
	std::cout << n3.mData.get() << std::endl;
}
