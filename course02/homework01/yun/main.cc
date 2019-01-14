#include "linkedlist.h"
#include <iostream>
#include <cassert>


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

	return 0;
}
