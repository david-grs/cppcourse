#include <iostream>
#include <vector>
#include <array>

void foo(int&) { std::cout << "foo(int&)" << std::endl; }
void foo(const int&) { std::cout << "foo(const int&)" << std::endl; }
void foo(int, int) { std::cout << "foo(int, int)" << std::endl; }
void foo(char, int) { std::cout << "foo(char, int)" << std::endl; }


template <class... Args>
void proxy(Args&&... args)
{
	foo(std::forward<Args>(args)...);
}

void* operator new(std::size_t bytes)
{
	std::cout << "allocation: " << bytes << std::endl;
	return std::malloc(bytes);
}

class A
{
public:
	A() =default;
	explicit A(int) { std::cout << "A()" << std::endl; }
	~A() { std::cout << "~A()" << std::endl; }

	A(const A&) { std::cout << "A(const A&)" << std::endl; }
	A& operator=(const A&) { std::cout << "operator=(const A&)" << std::endl; return *this; }

	A(A&&) { std::cout << "A(A&&)" << std::endl; }
	A& operator=(A&&) { std::cout << "operator=(A&&)" << std::endl; return *this; }
};

template <class T>
class Store
{
public:
	/*
	template <class... Args>
	void Add(Args&&... args)
	{
		mEntries.emplace_back(std::forward<Args>(args)...);
	}
	*/

	void Add(const T& t)
	{
		mEntries.push_back(t);
	}

	void Add(T&& t)
	{
		mEntries.push_back(std::move(t));
	}

	template <class U>
	void Add(U&& t)
	{
		mEntries.push_back(std::move(t));
	}

private:
	std::vector<T> mEntries;
};


template <class T>
struct Vector
{
	Vector(Vector&& rhs) :
		mSize(rhs.mSize),
		  mCapacity(rhs.mCapacity),
		  mBuffer(rhs.mBuffer)
	{
	}

private:
	int mSize;
	int mCapacity;
	T* mBuffer;
};

int main()
{
	Store<A> store;
	store.Add(A{5});

	//store.Emplace(5);

	/*
	int i = 3;
	proxy(i);
	proxy(5);

	proxy(6, 2);*/
	return 0;
}

