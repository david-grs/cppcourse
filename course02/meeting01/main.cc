#include <iostream>
#include <cstdint>

void foo(int& i)
{
	i *= 2;
}

void bar(const std::string& s)
{}

int& matt(int f)
{
	static int complex = 1234;
	complex += f;
	return complex;
}

void foo(A* a, B* b, C* c);

int main()
{
	foo(&a, nullptr, nullptr);

	int i = 5;
	int& j = i;

	foo(i);

	int* ptri = nullptr;
	ptri = &i; // address-of operator
	*ptri += 1; // dereference operator

	std::cout << *ptri << std::endl;

	std::cout << j << std::endl;
}

#if 0
void foo(int& i)
{
	i = 5;
}


int main(int argc, char** argv)
{
	const std::string appName{argv[0]};
	int argsCount = argc;

	foo(argsCount);

	std::cout << appName << ": argc=" << argsCount << std::endl;

	char c = 's'; // string
	std::string str;

	signed char d; // ?
	unsigned char e; // -> std::byte

	int i;
	unsigned int volume = -1;

	// short s;
	// long l;
	// long long ll;

	std::uint16_t port;
	std::int64_t price;

	bool b = true;

	return 0;
}
#endif
