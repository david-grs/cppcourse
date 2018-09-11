// Copyright (c) Optiver I.P. B.V. 2018
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "unique_ptr.h"


class Foo
{
public:
	Foo()
		: Foo("Message")
	{
	}

	Foo(const std::string& message)
	{
		std::cout << "Foo()" << message << std::endl;
		this->message = message;
	}
	~Foo()
	{
		std::cout << "~Foo()" << message << std::endl;
	}
	void DoStuff() const
	{
		std::cout << message << std::endl;
	}
private:
	std::string message;
};

template <typename T>
unique_ptr<T> make_unique()
{
	return unique_ptr<T>(new T());
}


TEST(Test, UniquePtrTest)
{
	unique_ptr<Foo> fooptr = make_unique<Foo>();	
	//(*fooptr).DoStuff();
	fooptr->DoStuff();	
	fooptr.reset(new Foo("Other message"));
}
