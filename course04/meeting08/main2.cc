#include <iostream>
#include <vector>
#include <cstring>

template <class ReturnT, class T, class U>
ReturnT Min(T x, U y)
{
	std::cout << "1" << std::endl;
	return y < x ? y : x;
}

template <class T>
T Min(T x, T y)
{
	std::cout << "2" << std::endl;
	return y < x ? y : x;
}

int Min(int x, int y)
{
	std::cout << "3" << std::endl;
	return y < x ? y : x;
}

template <>
const char* Min(const char* x, const char* y)
{
	return std::strcmp(x, y) > 0 ? y : x;
}

int main()
{
	std::cout << Min(6, 5) << std::endl;
	std::cout << Min("foo", "bar") << std::endl;
	return 0;
}
