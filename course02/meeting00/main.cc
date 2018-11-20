#include <iostream>
#include <thread>
#include <chrono>

int i;
int j = 5;

int main()
{
	int k = 10;

	std::cout << &i << std::endl;
	std::cout << &j << std::endl;
	std::cout << &k << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(100));
	return 0;
}
