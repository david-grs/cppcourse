#pragma once

#include <iostream>

class Foo
{
public:
	Foo(int i) :
		mI(i)
	{
		//std::cout << "Foo(" << i << ")" << std::endl;
	}

	~Foo()
	{
		//std::cout << "~Foo()" << std::endl;
	}

	Foo(const Foo& other) :
		mI(other.mI)
	{
		//std::cout << "Foo(const Foo&)" << std::endl;
	}

	Foo& operator=(const Foo& other)
	{
		mI = other.mI;
		//std::cout << "operator=(const Foo&)" << std::endl;
		return *this;
	}

private:
	int mI;
};
