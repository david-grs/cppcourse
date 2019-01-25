#include "list.h"

#include <iostream>
#include <vector>

#include <algorithm>
#include <numeric>

template <class T, std::size_t N>
class Array
{
public:
	using iterator = T*;

	T* begin() { return mData; }
	T* end() { return mData + N; }

	T mData[N];
};

int main()
{
	LinkedList<int> l;
	l.push_front(3);
	l.push_front(2);
	l.push_front(1);

	for (int i : l)
		std::cout << i << std::endl;

	//std::vector<int> v(l.begin(), l.end());

	const int s = std::accumulate(l.begin(), l.end(), 0);
	std::cout << s << std::endl;

	auto it = std::find(l.begin(), l.end(), 1);


	/*
	Array<int, 4> ar{0,1,2,3};
	for (Array<int, 4>::iterator it = ar.begin(); it != ar.end(); ++it)
		std::cout << i << std::endl;
	*/

	return 0;
}


#if 0

template <class FirstT, class SecondT>
class Pair
{
public:
	using first_type = FirstT;
	using second_type = SecondT;

	template <class T, class U>
	Pair(const T& first, const U& second) :
		mFirst(first), mSecond(second)
	{}

	FirstT mFirst;
	SecondT mSecond;
};


int main()
{
	Pair<double, int> priceVolume{2.5, 100};
	return 0;
}

#endif

