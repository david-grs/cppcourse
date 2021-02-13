#include <iostream>
#include <string>

void bar(int j)
{
	const std::string foo = "bar";
}

void foo(int i)
{
	int k = 5;
	bar(i);
}

int main(int argc, char* argv[])
// Some fun reading material about consts here: https://stackoverflow.com/questions/20558418/why-is-argc-not-a-constant
// I gave up rather quickly
{
	if (argc != 2)
	{
		std::cerr << "usage: " << argv[0] << " name" << std::endl;
		return 1;
	}

	const std::string name{argv[1]};
	const std::string greeting{"Hello, " + name};

	std::cout << greeting << std::endl;
	foo(3);
	return 0;
}
 
