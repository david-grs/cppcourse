#include "linkedlist.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <numeric>


int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

	LinkedListInt l;
	assert(l.size() == 0);

	// for (int i = 0; i < 1000000000; i++) {
	// 	if (i % 1000000 == 0) {
	// 		std::cout << i << std::endl;
	// 	}
	// 	l.push(i);
	// }

	// for (int i = 0; i < 1000000000; i++) {
	// 	l.pop_head();
	// }

	l.push(1);
	assert(l.size() == 1);
	l.push(2);
	assert(l.size() == 2);
	int head = l.pop_head();
	assert(head == 2);
	assert(l.size() == 1);
	l.clear();
	assert(l.size() == 0);

	l.push(4);
	l.push(100);
	double sum = std::accumulate(l.begin(), l.end(), 0.0);
	double mean = sum / l.size();
	double sq_sum = std::inner_product(l.begin(), l.end(), l.begin(), 0.0);
	double stdev = std::sqrt(sq_sum / l.size() - mean * mean);
	assert(mean == 52.0);
	assert(stdev == std::sqrt(2304.0));

	return 0;
}
