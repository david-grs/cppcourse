#include "vector.h"

#include <cassert>

void test_size()
{
	VectorInt v;
	assert(v.size() == 0);
	v.push_back(5);
	v.push_back(6);
	assert(v.size() == 2);
}

void test_at()
{
	VectorInt v;
	bool throws = false;
	try{
		v.at(0);
	}
	catch (std::out_of_range&)
	{
		throws = true;
	}
	assert(throws);
	v.push_back(5);
	assert(v.at(0) == 5);
}

void test_capacity()
{
	VectorInt v;
	assert(v.capacity() == 128);
	for(int i=0; i < 128; i++)
		v.push_back(1);

	bool throws = false;
	try {
		v.push_back(1);
	}
	catch (std::out_of_range&)
	{
		throws = true;
	}

	assert(throws);
}

void test_back()
{
	VectorInt v;
	v.push_back(1);
	assert(v.back() == 1);
	v.clear();

	bool throws = false;
	try {
		v.back();
	}
	catch(std::out_of_range&)
	{
		throws = true;
	}
	assert(throws);
}

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

	test_size();
	test_at();
	test_capacity();
	test_back();
	return 0;
}
