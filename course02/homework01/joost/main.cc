#include "linkedlist.h"
#include <cassert>
#include <iostream>

int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

	LinkedListInt l;
	assert(l.size() == 0);
	l.append(10);
	l.append(20);
	l.append(30);
	assert(l.size() == 3);
	assert(l.pop_front() == 10);
	assert(l.pop_front() == 20);
	assert(l.pop_front() == 30);
	assert(l.size() == 0);

	return 0;
}

