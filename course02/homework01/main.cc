#include "linked_list.h"
#include <cassert>

using namespace std;
int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

	LinkedList v;
	bool catchedError = false;

	assert(v.Empty());
	
	v.Insert(5);
	v.Insert(2);
	v.Insert(7);

	assert(v.Size() == 3);
	assert(!v.Empty());

	auto* node = v.Find(5);
	assert(node->data == 5);

	v.Remove(2);
	assert(v.Size() == 2);

	try
	{
		v.Remove(2);
	}
	catch(LinkedListError&) 
	{
		catchedError = true; 
	}
	assert(catchedError);

	node = v.Find(2);
	assert(node == v.End());

	cout << v << endl;

	v.Remove(5);
	v.Remove(7);

	cout << v << endl;

	return 0;
}
