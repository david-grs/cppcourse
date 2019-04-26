#include <iostream>

#include <vector>
#include <string>

// parameter-in: pass by value ONLY if size <= word
void bar(std::vector<std::string>);
void bar2(const std::vector<std::string>&);

// parameter-out
void bar2(std::vector<std::string>&);

void foo(int* pi)
{
	if (pi != nullptr)
	{
		*pi += 1; // dereference operator
	}
}

class B
{
public:
	B(int i = 0)
	{
		std::cout << "B(" << i << ")" << std::endl;
	}
};

class A
{
public:
	explicit A(int& i) :// user defined ctor
		mB{i},
		mI{i},
		mJ{mI}
	{}

private:
	std::vector<std::string> mStrings;
	B mB;
	const int mI;
	const int& mJ;
};

void foo(const A& a) {}

int main()
{
	{
		Socket s{"80.0.0.1", 123};
	} // ~Socket()

	//foo(5);

	int ii = 5;
	A a{ii};






	int i = 5;
	std::cout << &i << std::endl;

	int* pi;
	{
		int k = 1;
		pi = &k;
	}

	std::cout << *pi << std::endl;
	pi = &i; // address-of operator
	pi = nullptr;

	return 0;
}
