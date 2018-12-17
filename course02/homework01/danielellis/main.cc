#include "linkedlist.h"

#include <cassert>

int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

	LinkedList l;
	assert(l.Size() == 0);

	l.Append(1);
	assert(l.At(0) == 1);
	assert(l.Size() == 1);

	for (int i = 0; i < 100; ++i)
	{
		l.Append(i);
		assert(l.At(i+1) == i);
	}

	assert(l.Size() == 101);
	assert(l.At(1) == 0);
	assert(l.At(50) == 49);

	return 0;
}
