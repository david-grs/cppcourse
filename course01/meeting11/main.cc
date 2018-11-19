#include <iostream>
#include <thread>
#include <chrono>

int64_t i = 0;
char something[245];
int64_t j = 0;

int main()
{
	auto start = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	auto start2 = std::chrono::steady_clock::now();
	auto end2 = std::chrono::steady_clock::now();

	std::thread worker([&]()
	{
		start = std::chrono::steady_clock::now();
		while (++i < 2000000000);
		end = std::chrono::steady_clock::now();
	});
	std::thread worker2([&]()
	{
		start2 = std::chrono::steady_clock::now();
		while (++j < 2000000000);
		end2 = std::chrono::steady_clock::now();
	});

	std::cout << "start" << std::endl;
	worker.join();
	worker2.join();
	std::cout << "stop" << std::endl;
	std::cout << "worker1: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
	std::cout << "worker2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << "ms" << std::endl;

	return 0;
}
