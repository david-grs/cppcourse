#include "linked_list.h"
#include <cassert>

void test_push_back()
{
	LinkedList linkedList;

	linkedList.PushBack(0);

	assert(!linkedList.Empty());
	assert(linkedList.Size() == 1);
}

void test_erase_at()
{
	LinkedList linkedList;

	linkedList.PushBack(0);
	linkedList.PushBack(1);
	linkedList.PushBack(2);

	linkedList.EraseAt(1);

	assert(linkedList.Size() == 2);
}

void test_erase_at_bad()
{
	LinkedList linkedList;

	bool catchedError = false;
	try 
	{
		linkedList.EraseAt(0);
	}
	catch(std::exception&)
	{
		catchedError = true;
	}

	assert(catchedError);
}

void test_get_at()
{
	LinkedList linkedList;

	linkedList.PushBack(0);
	linkedList.PushBack(1);

	auto& node = linkedList.At(0);
	assert(node.mData == 0);
}

void test_get_at_bad()
{
	LinkedList linkedList;

	bool catchedError = false;
	try
	{
		linkedList.At(0);
	}
	catch (std::exception&)
	{
		catchedError = true;
	}

	assert(catchedError);
}

void test_print_linked_list()
{
	LinkedList linkedList;

	linkedList.PushBack(5);
	linkedList.PushBack(2);
	linkedList.PushBack(7);

	std::cout << linkedList << std::endl;
}

int main()
{
#ifdef NDEBUG
#error Compile the code in debug mode!
#endif

	test_push_back();
	test_erase_at();
	test_erase_at_bad();
	test_get_at();
	test_get_at_bad();
	test_print_linked_list();

	return 0;
}
