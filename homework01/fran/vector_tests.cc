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
}
