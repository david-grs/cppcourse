#include <iostream>
#include <array>

class String
{
public:
	static constexpr const std::size_t MaxSize = 32;

	String();
	String(const std::string&);

	std::size_t size() const { return mSize; }
	std::size_t max_size() const { return MaxSize; }
	std::size_t capacity() const { return MaxSize; }

	const char* c_str() const { return mData.data(); }

private:
	std::size_t mSize = 0;
	std::array<char, MaxSize> mData;
};

String::String()
{
	mData[0] = 0;
}

String::String(const std::string& str) :
	mSize{str.size()}
{
	if (mSize + 1 > max_size())
		throw std::out_of_range("...");

	std::copy(str.data(), str.data() + mSize + 1, mData.data());
}

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	stream << str.c_str();
	return stream;
}

int main()
{
	String s(std::string("foofoofoofoofoofoofoofoofoo"));
	std::cout << s << std::endl;
	return 0;
}


/*
class A
{
public:
	// rule of zero
	A() =default;

	// user defined ctor: this INHIBITS the default ctor
	explicit A(int i) :
		mI{i},
		mJ{i}
	{
		std::cout << "A(" << i << ")" << std::endl;
	}

private:
	int mI;
	const int mJ;
	//int& mK;
};


class B
{
public:
	B() : mA{6} // mI = 6, mJ = 6
	{
		// mA = A{5}; // mI = 6, mJ = 5 ?
	}

private:
	A mA;
};

int main()
{
	B b;

	std::vector<A> v(10);
}
*/

/*


int main()
{

}
*/
/*

#include <iostream>

#include "example0.h"
#include "example1.h"
#include "example2.h"
#include "example3.h"
#include "example4.h"

int main()
{
	example0();
	example1();
	example2();
	example3();
	example4();

	return 0;
}

*/

