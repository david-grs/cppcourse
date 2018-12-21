#include <iostream>

class unique_ptr_int
{
public:
	unique_ptr_int() :
		mPtr(nullptr)
	{}

	explicit unique_ptr_int(int i) :
		mPtr(new int(i))
	{}

	~unique_ptr_int()
	{
		delete mPtr;
	}

	unique_ptr_int(const unique_ptr_int&) =delete;
	unique_ptr_int& operator=(const unique_ptr_int&) =delete;

	int operator*() const { return *mPtr; }

private:
	int* mPtr;
};


int Max(int a, int b)
{
	std::cout << "1" << std::endl;
	return a < b ? b : a;
}

template <class T>
T Max(T a, T b)
{
	std::cout << "2" << std::endl;
	return a < b ? b : a;
}

template <class T, class U, class ReturnT>
ReturnT Max(T a, U b)
{
	std::cout << "3" << std::endl;
	return a < b ? b : a;
}

template <>
int Max(int a, int b)
{
	std::cout << "4" << std::endl;
	return a < b ? b : a;
}

template <class ValueT>
class Vector
{
public:
	using value_type = ValueT;
};


template <class Container>
typename Container::value_type Sum(const Container& container)
{
	using ValueT = typename Container::value_type;
	// TODO
}


int main()
{
	Vector<int> v;
	Sum(v);

	std::cout << Max(3, 4) << std::endl;
	//unique_ptr_int ui(4);
	//std::cout << *ui << std::endl;

	return 0;
}
