#include <iostream>
#include <cmath>

// instance of a class = object
// class "invariants"
class Vector2D
{
public:
	Vector2D(double x, double y) :
		mX{x},
		mY{y}
	{
		if (!std::isfinite(mX) || !std::isfinite(mY))
			throw std::runtime_error("non finite");
	}

	double GetX() const { return mX; }
	double GetY() const { return mY; }

private:
	double mX;
	double mY;
};

/*
struct Vector2D
{
	double mX;
	double mY;
};
*/

// class : invariants
// struct : no invariants

struct A // struct = class + public by default
{
	A()
	{
		std::cout << "A()" << std::endl;
	}

	explicit A(int i)
	{
		std::cout << "A(" << i << ")" << std::endl;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

struct B
{
	B() :
		mA{5}, // initializer-list
		mI{1}
	{
		std::cout << "B() " << std::endl;
	}

	A mA;
	int mI;
};

void foo(A a) {}

int main()
{
	B b;

	foo(A{5});

	A a{5};
	foo(a);

	foo(5);


	Vector2D v{1.0, 2.0}; // stack -> sub sp, 16
	std::cout << v.GetX() << std::endl;
	std::cout << sizeof(Vector2D) << std::endl;


	return 0;
}



#if 0
#include "example0.h"
#include "example1.h"
#include "example2.h"
#include "example3.h"
#include "example4.h"
#include "example5.h"
#include "example6.h"

#include <iostream>

#include <boost/numeric/conversion/cast.hpp>

int main()
{
	//example0();
	//example1();
	//example2();
	//example3();
	//example4();
	//example5();
	example6();

	std::uint64_t volume = 1e16;
	int volume2 = boost::numeric_cast<int>(volume); // C-style cast -> *never* use it
	std::cout << volume2 << std::endl;


	using Delta = Common::StrongTypedef<double>; // common/strong_typedef.hpp
	Delta delta;
	Gamma gamma = delta * 2;

	double d;
	float f;

	THROW_IF(!std::isfinite(d), "..."); // common/throw_if.hpp

	if (!std::isfinite(d))
		throw std::runtime_error("...");

	return 0;
}

#endif
