#include "list.h"

#include <cassert>
#include <list>
#include <iostream>
#include <algorithm>

struct TestDisposableClass
{
	int& disposeCounter;

	TestDisposableClass(int & disposeCounter) :
		disposeCounter(disposeCounter)
	{ }

	~TestDisposableClass()
	{
		disposeCounter++;
	}
};

struct TestCallableClass
{
	int value;

	TestCallableClass(int value) :
		value(value)
	{ }

	int foo() const
	{
		return value;
	}
};

void test_empty()
{
	List<int> l;

	assert(l.empty());
	assert(l.size() == 0);
}

void test_push_back()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	assert(l.front() == 1);
	assert(l.back() == 4);
	assert(l.size() == 4);
}

void test_push_front()
{
	List<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);

	assert(l.front() == 4);
	assert(l.back() == 1);
	assert(l.size() == 4);
}

void test_forward_iterator()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	auto iter = l.begin();

	assert(*(iter++) == 1);
	assert(*(iter++) == 2);
	assert(*(iter++) == 3);
	assert(*(iter++) == 4);
	assert(iter == l.end());
}

void test_backward_iterator()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	auto iter = l.end();

	assert(*(--iter) == 4);
	assert(*(--iter) == 3);
	assert(*(--iter) == 2);
	assert(*(--iter) == 1);
	assert(iter == l.begin());
}

void test_bidirectional_iterator()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	auto iter = l.begin();

	assert(*(iter++) == 1);
	assert(*(iter--) == 2);
	assert(*(iter++) == 1);
	assert(*(iter++) == 2);
	assert(*(iter--) == 3);
	assert(*(iter++) == 2);
	assert(*(iter++) == 3);
	assert(*(iter++) == 4);
	assert(iter == l.end());
}

void test_pop_back()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	l.pop_back();

	assert(l.front() == 1);
	assert(l.back() == 3);
	assert(l.size() == 3);
}

void test_pop_front()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	l.pop_front();

	assert(l.front() == 2);
	assert(l.back() == 4);
	assert(l.size() == 3);
}

void test_pop_all()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	l.pop_back();
	l.pop_front();
	l.pop_back();
	l.pop_front();

	assert(l.empty());
	assert(l.size() == 0);
}

void test_insert_begin()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	auto iter = l.begin();
	l.insert(iter, 10);

	assert(l.size() == 5);
	assert(l.front() == 10);
	assert(*(--iter) == 10);
}

void test_insert_end()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	auto iter = l.end();
	l.insert(iter, 10);

	assert(l.size() == 5);
	assert(l.back() == 10);
	assert(*(--iter) == 10);
}

void test_insert_in_the_middle()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	auto iterA = l.begin();
	iterA++;
	iterA++;
	l.insert(iterA, 10);

	auto iterB = l.begin();

	assert(l.size() == 5);
	assert(*(iterB++) == 1);
	assert(*(iterB++) == 2);
	assert(*(iterB++) == 10);
	assert(*(iterB++) == 3);
	assert(*(iterB++) == 4);
}

void test_deconstruction()
{
	int disposeCounter;

	{
		List<TestDisposableClass> l;

		l.push_back(TestDisposableClass(disposeCounter));
		l.push_back(TestDisposableClass(disposeCounter));
		l.push_back(TestDisposableClass(disposeCounter));
		l.push_back(TestDisposableClass(disposeCounter));

		disposeCounter = 0;

		l.pop_back();

		assert(disposeCounter == 1);

		l.pop_front();

		assert(disposeCounter == 2);
	}

	assert(disposeCounter == 4);
}

void copy_constructor_test()
{
	List<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	List<int> b = a;

	a.insert(--a.end(), 10);

	auto iterA = a.begin();

	assert(a.size() == 5);
	assert(*(iterA++) == 1);
	assert(*(iterA++) == 2);
	assert(*(iterA++) == 3);
	assert(*(iterA++) == 10);
	assert(*(iterA++) == 4);
	assert(iterA == a.end());

	auto iterB = b.begin();

	assert(b.size() == 4);
	assert(*(iterB++) == 1);
	assert(*(iterB++) == 2);
	assert(*(iterB++) == 3);
	assert(*(iterB++) == 4);
	assert(iterB == b.end());
}

void assign_operator_test()
{
	List<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	List<int> b;

	b = a;

	a.insert(--a.end(), 10);

	auto iterA = a.begin();

	assert(a.size() == 5);
	assert(*(iterA++) == 1);
	assert(*(iterA++) == 2);
	assert(*(iterA++) == 3);
	assert(*(iterA++) == 10);
	assert(*(iterA++) == 4);
	assert(iterA == a.end());

	auto iterB = b.begin();

	assert(b.size() == 4);
	assert(*(iterB++) == 1);
	assert(*(iterB++) == 2);
	assert(*(iterB++) == 3);
	assert(*(iterB++) == 4);
	assert(iterB == b.end());
}

void const_iterator_test()
{
	List<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	const List<int> b = a;

	int sum = 0;

	for (auto element : b)
		sum += element;

	assert(sum == 10);
}

void mutation_test()
{
	List<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	auto iterA = a.begin();
	iterA++;
	*iterA = 10;

	auto iterB = a.begin();

	assert(*(iterB++) == 1);
	assert(*(iterB++) == 10);
	assert(*(iterB++) == 3);
	assert(*(iterB++) == 4);
}

void call_test()
{
	List<TestCallableClass> a;

	a.push_back(TestCallableClass(1));
	a.push_back(TestCallableClass(2));
	a.push_back(TestCallableClass(3));
	a.push_back(TestCallableClass(4));

	int sum = 0;

	for (auto iter = a.begin(); iter != a.end(); ++iter)
		sum += iter->foo();

	assert(sum == 10);
}

void max_test()
{
	List<int> a;

	a.push_back(3);
	a.push_back(1);
	a.push_back(5);
	a.push_back(4);
	a.push_back(2);

	auto max = std::max_element(a.begin(), a.end());

	assert(*max == 5);
}

void count_test()
{
	List<int> a;

	a.push_back(3);
	a.push_back(1);
	a.push_back(5);
	a.push_back(4);
	a.push_back(2);

	auto count = std::count_if(a.begin(), a.end(), [](int a) {return a >= 3; });

	assert(count == 3);
}

void remove_test()
{
	List<int> a;

	a.push_back(3);
	a.push_back(1);
	a.push_back(5);
	a.push_back(4);
	a.push_back(2);

	auto end = std::remove_if(a.begin(), a.end(), [](int a) {return a >= 3; });

	for (auto iter = a.begin(); iter != end; iter++)
		assert(*iter < 3);
}

void reverse_test()
{
	List<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);

	std::reverse(++a.begin(), --a.end());

	auto iter = a.begin();

	assert(*(iter++) == 1);
	assert(*(iter++) == 5);
	assert(*(iter++) == 4);
	assert(*(iter++) == 3);
	assert(*(iter++) == 2);
	assert(*(iter++) == 6);
}

int main()
{
	test_empty();
	test_push_back();
	test_push_front();
	test_forward_iterator();
	test_bidirectional_iterator();
	test_backward_iterator();
	test_pop_back();
	test_pop_front();
	test_pop_all();
	test_insert_begin();
	test_insert_end();
	test_insert_in_the_middle();
	test_deconstruction();
	copy_constructor_test();
	assign_operator_test();
	const_iterator_test();
	mutation_test();
	call_test();
	max_test();
	count_test();
	remove_test();
	reverse_test();
}
