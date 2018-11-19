#include "vector.h"

#include <iostream>
#include <cassert>

int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

	Vector v1;
	Vector v2(5, 6);

	assert(v2.GetX() == 5);
	assert(v2.GetY() == 6);

	v1 = v2;
	assert(v1.GetX() == 5);
	assert(v1.GetY() == 6);
	assert(v1 == v2);

	Vector v3(1, 2);
	v1.Add(v3);
	assert(v1.GetX() == 6);
	assert(v1.GetY() == 8);
	
	v3 = v2 + Vector(1, 1);
	assert(v3.GetX() == 6);
	assert(v3.GetY() == 7);

	v3 += v3;
	assert(v3.GetX() == 12);
	assert(v3.GetY() == 14);

	std::cout << v1 << " + " << v2 << " = " << v3 << std::endl;
}
