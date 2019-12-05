#include <iostream>
#include <set>
#include <algorithm>
#include "min.h"

// type "erasure"

//struct Shape { virtual std::vector<Point> GetVertices() const =0; };

struct Rectangle { std::vector<Point> GetVertices() const; };
struct Circle {};
struct Square {};

template <class Shape>
void Draw(const Shape& shape)
{
	shape.GetVertices();
}

int main()
{
	int x = 1;

	if (x < 0)
		std::cout << Min(5, 6) << std::endl;
	else
		std::cout << Min(5., 6.) << std::endl;

	std::cout << Max(5, 6) << std::endl;
	return 0;
}


/*
#include <cstring>
#include <cmath>
#include <iostream>

extern "C"
{
std::size_t strlen(const char*) { return 77; }
}

// ODR One Definition Rule
float log(float) { return 44; }
std::size_t strlen(float) { return 77; }

int main()
{
	std::cout << log(1.f) << std::endl;
	std::cout << std::log(1.f) << std::endl;
	std::cout << strlen("foo") << std::endl;
	std::cout << std::strlen("foo") << std::endl;
}
*/
