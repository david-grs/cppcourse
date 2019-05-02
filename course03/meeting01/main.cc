#include <cassert>
#include <iostream>
#include <thread>
#include <chrono>

int i = 1;
int j;

using namespace std::chrono_literals;

int* foo()
{
	return &i;
}

/*
int main(int argc, char** argv)
{
	int k;

	std::cout << &i << std::endl;
	std::cout << &j << std::endl;
	std::cout << &k << std::endl;
	std::cout << "foo " << std::endl;

	std::this_thread::sleep_for(30s);

	return 0;
}
*/

#include "example3.h"

#include <boost/numeric/conversion/cast.hpp>

int main()
{

	//std::cout << typeid(example3()).name() << std::endl;

	double d1, d2;
	//if (abs(d1 - d2) < epsilon)

	if (!std::isfinite(d1))
		throw;

	int_fast8_t k;
	int kk;
	uint32_t i;

	int foo = 1000;
	char cc = boost::numeric_cast<char>(foo);



}




