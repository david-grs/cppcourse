#include <iostream>

#if 0

// parameter "IN"
void baz(int); // <= 8 bytes (on x86)
void baz(const std::vector<std::string>&); // > 8 bytes

// parameter "OUT" or "IN-OUT"
void bar(int&);
void bar(std::vector<std::string>&);

#endif

// pointer = optional reference

void foo(int* pi)
{
	std::cout << *pi << std::endl;
	*pi = 5;
}

int main()
{
	int i = 123;
	int& j = i; // 2) cannot "rebind" the reference
	//int& k; // reference: 1) always have to bind to a value
	int* pk = &i;
	*pk = 0xdead;
	pk = nullptr;
	*pk = 0xdead;

	std::cout << i << std::endl;
	std::cout << j << std::endl;

	std::cout << &i << std::endl; // &: address-of operator
	std::cout << &j << std::endl;

	int* pi = &i;
	std::cout << pi << std::endl;

	pi += 4;
	std::cout << pi << std::endl;
	std::cout << *pi << std::endl; // *: dereference operator

	j = 6;

	foo(i);

	std::cout << i << std::endl; // VALUE SEMANTICS
	std::cout << j << std::endl; // VALUE SEMANTICS

	return 0;
}



#if 0

#include "foo.h"

// 3 steps: Preprocessor ---text---> Compilation ---- binary code .o ----> Linkage ----> binary
// Compilation
//   * Parsing, lexing
//   * IR -> intermediate representation ("LLVM IR")
//   * Optimization on IR
//   * Translation to assembly (architecture specific)
//   * Optimization on assembly

int main()
{
	Order order{1,2};
	return (int)order.VeryExpensiveCalculation();
}




#include <boost/optional.hpp>

class Order
{
public:
	Order(double price, double volume) :
		mPrice{price},
		mVolume{volume}
	{}

	double GetOrderValue()
	{
		if (!mOrderValue)
		{
			mOrderValue = VeryExpensiveCalculation();
		}
		return mOrderValue.get();
	}

private:
	double VeryExpensiveCalculation() const
	{
		return mPrice * mVolume * 0.1234;
	}

	double mPrice;
	double mVolume;
	boost::optional<double> mOrderValue;
};

enum struct IsDummy { Yes, No };
enum struct IsGFD { Yes, No };

int main()
{
	Order order{1, 2};
	//order.mOrderValue = 100.;
	return 0;
}

#endif
