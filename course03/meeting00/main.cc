#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	const std::string name{argv[1]};

	std::string greeting = "Hello, " + name;
	std::cout << greeting << std::endl;

	return 0;
}
