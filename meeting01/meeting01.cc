#include <iostream>
#include <iomanip>
#include <cstdint>

int i = 10;

class Point
{
public:
	void Print()
	{
		std::cout << "x=" << x << ", y=" << y << std::endl;
	}

private:
	int x;
	int y;
};

void bar()
{
	//int x = 1;
	//int y = 3;

	Point p{2, 3};
	p.Print();

	std::cout << p.x << std::endl;
}

void foo()
{	
	int ii2 = 1;
	char c = '0';
	int ii = 0;
	std::cout << "foo::ii2=" << std::hex << &ii2 << std::endl;
	std::cout << "foo::c=" << std::hex << (void*)&c << std::endl;
	std::cout << "foo::ii=" << std::hex << &ii << std::endl;
}

int main()
{
	bar();

	unsigned int j = -1;
	int k = -1;
	std::cout << j  << std::endl;
	
	if (j < k)
		std::cout << "BOOM " << std::endl;

	std::size_t ss;

	std::uint32_t u;
	std::int8_t u2;

	std::int_least32_t gg;
	std::uint_fast8_t hh; 
	foo();

	std::cout << i << std::endl;
	std::cout << std::hex << &i << std::endl;

	return 0;
}
