#include <iostream>
#include <vector>

template <class T>
T Max(T a, T b)
{
	std::cout << "max1" << std::endl;
	return a < b ? b : a;
}

template <class T, class U, class Return = T>
Return Max(T a, U b)
{
	std::cout << "max2" << std::endl;
	return Return{a < b ? b : a};
}

template <>
int Max(int a, int b)
{
	std::cout << "max4" << std::endl;
	return a > b ? b : a;
}

int Max(int a, int b)
{
	std::cout << "max3" << std::endl;
	return a < b ? b : a;
}

template <class Container>
void sort(Container&) {}

template <class Value>
void sort(std::vector<Value>&) {}


struct A
{
	template <typename T>
	static void bar() {}
};

struct B
{
	static const int buz = 0;
	static const int baz = 1;
	static const int bar = 2;
};

template <class T>
void foo()
{
	T::template bar<int>();
	//T::buz < T::baz > T::bar;
}


int main()
{
	std::cout << Max(5, 6) << std::endl;
	foo<A>();
	//foo<B>();

}
