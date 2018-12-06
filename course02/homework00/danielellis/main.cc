#include "vector.h"

#include <cassert>

int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

	VectorInt v;
	assert(v.size() == 0);
	assert(v.capacity() > 0);

	v.push_back(123);
	assert(v.size() == 1);
	assert(v.back() == 123);

	v.clear();
	assert(v.size() == 0);

	for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i);
	}
	assert(v.size() == 1000);
	assert(v.back() == 999);
	assert(v.at(500) == 500);

	return 0;
}
