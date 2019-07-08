#include <cstdlib>
#include <iostream>

#include <algorithm>
#include <numeric>

#include "forward_list.h"

template <class T, std::size_t N>
class Array
{
public:
	T* begin() { return &mData[0]; }
	T* end() { return &mData[N]; }

	T mData[N];
};

template <class ContainerT>
void sortImpl(ContainerT& c, std::forward_iterator_tag) {}

template <class ContainerT>
void sortImpl(ContainerT& c, std::random_access_iterator_tag) {}

template <class ContainerT>
void sort(ContainerT& c)
{
	sortImpl(c, typename std::iterator_traits<typename ContainerT::iterator>::iterator_category{});
}

int main()
{
	Array<int, 4> ar{0,2,4,6};

	for (int i : ar)
		std::cout << i << std::endl;


	ForwardList<int> f;
	f.push_front(6);
	f.push_front(4);
	f.push_front(2);
	f.push_front(0);

	for (int i : f)
		std::cout << i << std::endl;

	sort(f);

	//const int s = std::accumulate(f.begin(), f.end(), 0);
	//std::sort(f.begin(), f.end());



	return 0;
}
