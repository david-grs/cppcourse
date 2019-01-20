#include "vector.h"

#include <cassert>

void test_empty()
{
	VectorInt v;

	assert(v.empty());
	assert(v.size() == 0);
}

void test_one_element()
{
	VectorInt v;

	v.push_back(10);

	assert(!v.empty());
	assert(v.size() == 1);
	assert(v.front() == 10);
	assert(v.back() == 10);
}

void test_multiple_elements()
{
	VectorInt v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	assert(!v.empty());
	assert(v.size() == 3);
	assert(v.front() == 10);
	assert(v.back() == 30);
}

void test_out_of_range()
{
	VectorInt v;
	bool exception_thrown;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	exception_thrown = false;
	try { v.at(6); }
	catch (std::out_of_range) { exception_thrown = true; }
	assert(exception_thrown);

	exception_thrown = false;
	try { v[6]; }
	catch (std::out_of_range) { exception_thrown = true; }
	assert(!exception_thrown);
}

void test_clear()
{
	VectorInt v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v.clear();

	assert(v.size() == 0);
}

void test_iterator()
{
	VectorInt v;
	int sum = 0;
	int iterations = 0;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	for (auto& iter : v)
		iterations++;

	for (auto& iter : v)
		iter += 10;

	for (auto& iter : v)
		sum += iter;

	assert(iterations == 3);
	assert(v.front() == 20);
	assert(v[1] == 30);
	assert(v.back() == 40);
	assert(sum == 90);
}

void test_const_iterator()
{
	VectorInt v;
	int sum = 0;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	const VectorInt constV = v;

	for (auto& iter : constV)
		sum += iter;

	assert(sum == 60);
}

void test_full()
{
	VectorInt v;

	for (std::size_t i = 0; i < v.capacity(); i++)
		v.push_back(i);

	assert(v.full());
}

void test_too_many_elements()
{
	VectorInt v;
	bool exception_thrown = false;

	try 
	{ 
		for (std::size_t i = 0; i < v.capacity() + 1; i++)
			v.push_back(i);
	}
	catch (std::out_of_range) { exception_thrown = true; }
	assert(exception_thrown);
}

int main()
{
	test_empty();
	test_one_element();
	test_multiple_elements();
	test_out_of_range();
	test_clear();
	test_iterator();
	test_const_iterator();
	test_full();
	test_too_many_elements();
}
