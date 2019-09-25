#include <iostream>
#include <cassert>

// fundamental types: by value: void foo(int i)
// for the rest: by const ref:
void Print(const int& i)
{
	std::cout << i << std::endl;
}

int foo(int& i) // RVO / NRVO
{
	int i = 5;
	return i;
}

int main()
{
	int k;
	foo(k);
	std::cout << k << std::endl;

	int i = 5; // "automatic" storage
	int& r = i;
	assert(i == r);

	Print(r);
	std::cout << i << std::endl;
	std::cout << &i << std::endl;

	std::string* addressPtr;

	{
		std::string address{"AmsterdamAmsterdamAmsterdamAmsterdam"};
		addressPtr = &address;
	}

	std::cout << *addressPtr << std::endl;

	return 0;
}

#if 0

#include <boost/numeric/conversion/cast.hpp>
#include <cstddef>


enum struct Side { Bid, Ask };
void foo(Side, bool useB, bool useC);

int main()
{

	// fundamental types
	// - integral types
	// - floating point
	// - boolean
	float f;
	double d = 1 / .0;
	std::cout << d << std::endl;

	// guideline 3 :Common::Price, Common::Volume, Common::Decimal
	if (!std::isfinite(d))
	{
		std::abort();
	}


	/*
	char c;
	//short s= 66000;
	int i;
	long int l;

	unsigned char uc;
	unsigned short us;
	unsigned int ui;
	*/

	// guideline: always use signed integers
	using Volume = unsigned int;
	Volume v = 10;

	using Volume2 = int;
	Volume2 vv = -1;

	if (v > vv)
	{
		std::cout << "foo";
	}

	// guideline 2 : use numeric_cast
	uint16_t s = 66000;//boost::numeric_cast<uint16_t>(i);
	std::cout << s << std::endl;


	return 0;
}

#endif
