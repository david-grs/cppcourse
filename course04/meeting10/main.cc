#include <iostream>
#include <vector>

void Print(const int& l, const int& r) { std::cout << "const int&, const int&" << std::endl; }
void Print(int& l, const int& r) { std::cout << "int&, const int&" << std::endl; }
void Print(const int& l, int& r) { std::cout << "const int&, int&" << std::endl; }
void Print(int& l, int& r) { std::cout << "int&, int&" << std::endl; }

// universal reference -> modern "forward reference"
// perfect forwarding
template <class... Args>
void Proxy(Args&&... args)
{
	Print(std::forward<Args>(args)...);
}

int main()
{
	for (auto&& x : v)
		;

	int i = 0;
	Proxy(i, 2);
	return 0;
}
