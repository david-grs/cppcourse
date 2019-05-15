#include "foo.h"

#include <iostream>
#include <memory>
#include <chrono>
#include <cassert>
#include <algorithm>

Foo CreateFoo(int i)
{
	Foo f{i};

	if (i == 3)
		return Foo{123};

	return f;
}

std::unique_ptr<Foo> CreateFooHeap(int i)
{
	auto f = std::make_unique<Foo>(i);

	if (i == 3)
		return std::make_unique<Foo>(123);

	return f;
}

class unique_ptr_foo
{
public:
	unique_ptr_foo() =default;

	explicit unique_ptr_foo(int i) :
		mFooPtr(new Foo(i))
	{}

	~unique_ptr_foo()
	{
		delete mFooPtr;
	}

	unique_ptr_foo(const unique_ptr_foo&) =delete;
	unique_ptr_foo& operator=(const unique_ptr_foo&) =delete;

	Foo& operator*() { assert(mFooPtr != nullptr); return *mFooPtr; }
	Foo* operator->() { assert(mFooPtr != nullptr); return mFooPtr; }

private:
	Foo* mFooPtr = nullptr;
};


class Vector
{
public:
	Vector() =default;

	void push_back(int x)
	{
		if (mSize == mCapacity)
		{
			grow();
		}

		mData[mSize] = x;
		++mSize;
	}

	std::size_t size() const { return mSize; }
	std::size_t capacity() const { return mCapacity; }
	int operator[](std::size_t i) const { return mData[i]; }

private:
	void grow()
	{
		const std::size_t newCapacity = mCapacity * 2 + 1;
		auto newData = std::make_unique<int[]>(newCapacity);

		std::copy_n(mData.get(), mSize, newData.get());

		mCapacity = newCapacity;
		mData = std::move(newData);
	}

	std::unique_ptr<int[]> mData;
	std::size_t mSize = 0;
	std::size_t mCapacity = 0;
};


int main()
{
	Vector v;

	for (std::size_t i = 0; i < 100; ++i)
		v.push_back(i);

	for (std::size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << std::endl;


	unique_ptr_foo fff{4};

	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < 1000; ++i)
	{
		//const Foo f = CreateFoo(2);
		auto f = CreateFooHeap(2);
		asm volatile("" : : "r,m"(f.get()) : "memory");
	}
	auto end = std::chrono::steady_clock::now();
	std::cout << (end - start).count() / 1000. << "ns/it" << std::endl;

	const Foo f = CreateFoo(2);
	//auto ff = CreateFooHeap(2);

	return 0;
}
