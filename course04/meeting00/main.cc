#include <cassert>
#include <iostream>

int i = 0;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "usage: " << argv[0] << " name" << std::endl;
		return 1;
	}

	int j = 0;
	
	std::cout << &i << std::endl;
	std::cout << &j << std::endl;

	const std::string name{argv[1]};
	const std::string greeting = "Hello, " + name;

	std::cout << greeting << std::endl;
	return 0;
}
