#include "vector.h"

#include <cassert>

void larger_vector()
{
	VectorInt v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	assert(v.size() == 5);
	assert(v.back() == 5);
	assert(v.back() == 4);
	assert(v.back() == 3);
	assert(v.back() == 2);
	assert(v.back() == 1);
	assert(v.size() == 0);
}

void too_much()
{
	VectorInt v;
	for(int i=0; i<v.capacity(); i++)
		v.push_back(i);
	assert(v.size() == v.capacity());
	bool caught = false;
	try
	{
		v.push_back(12);
	}
	catch(std::out_of_range&)
	{
		caught = true;
	}
	assert(caught);
}

void back_from_empty()
{
	VectorInt v;
	bool caught = false;
	try
	{
		v.back();
	}
	catch(std::out_of_range&)
	{
		caught = true;
	}
	assert(caught);
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

	// Joost's tests
	larger_vector();
	too_much();
	back_from_empty();
	return 0;
}

