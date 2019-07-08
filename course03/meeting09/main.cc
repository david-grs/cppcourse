#include <list>
#include <iostream>
/*
template <class T, class... Args>
std::unique_ptr<T> make_unique(Args... args)
{
	return std::unique_ptr<T>(new T(args...));
}

*/

template <class Head, class... Args>
void Print(Head&& arg, Args&&... args)
{
	std::cout << arg << " ";

	if constexpr(sizeof...(args) > 0)
		Print(args...);
	else
		std::cout << std::endl;
}

int main()
{
	std::string ss = "foo";
	Print(ss, 5, 4.2);
}
