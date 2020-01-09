#include <iostream>
#include <vector>
#include <array>

template <class T>
struct Counter
{
	Counter() { ++sCtors; }
	Counter(const Counter&) { ++sCopyCtors; }
	Counter& operator=(const Counter&) { ++sCopyCtors; }
	Counter(Counter&&) { ++sMoveCtors; }
	Counter& operator=(Counter&&) { ++sMoveCtors; }

	static int sCtors;
	static int sCopyCtors;
	static int sMoveCtors;
};

template <class T> int Counter<T>::sCtors = 0;
template <class T> int Counter<T>::sCopyCtors = 0;
template <class T> int Counter<T>::sMoveCtors = 0;

struct BigObject : public Counter<BigObject> {}; // CRTP

template <class T>
class Store
{
public:
	void Add(T&& value) // "sink"
	{
		mElements.push_back(std::move(value));
	}

	template <class... Args>
	void Add(Args&&... args)
	{
		mElements.emplace_back(std::forward<Args>(args)...); // in place construction
	}

	std::vector<T> mElements;
};


int main()
{
	BigObject bo;

	Store<BigObject> store;
	store.Add(std::move(bo)); // store.Add(Counter{});

	std::cout << BigObject::sCtors << " ctors " << std::endl;
	std::cout << BigObject::sCopyCtors << " copy ctors " << std::endl;
	std::cout << BigObject::sMoveCtors << " move ctors " << std::endl;

	// bo = ?
	return 0;
}
