#include <iostream>

void print(int k)
{
	std::cout << k << std::endl;
}

int main()
{
	int i = 5;

	// i: l-value
	// 5: r-value
	i = 5;

	// 5 = i;
	// std::cout << &5 << std::endl;

	// declare ref
	// int & j = i;
	// int& j = i;
	int &j = i;

	j = 10;

	print(i);

	std::cout << i << std::endl;
	std::cout << j << std::endl;

	// address-of operator
	std::cout << &i << std::endl;


	int* p = &i + 20;
	*p = 20;
	std::cout << i << std::endl;

	
}


class A
{
public:
	A()
	{
		std::cout << "A() " << std::endl;
	}

	A(int i)
	{
		std::cout << "A(" << i << ")" << std::endl;
	}
};

class B
{
public:
	B() :
		mA(5)  
	{}

private:
	A mA;
};

#if 0
int main()
{
	B b;
}
#endif


