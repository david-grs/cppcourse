#include "linkedlist.h"

void LinkedList::push_front(int element)
{
	if (empty())
	{
		mHead = std::make_unique<Node>(element);
	}
	else
	{
		push_front_rec(element, *mHead);
	}

	++mSize;
}

void LinkedList::push_front_rec(int element, Node& root)
{
	if (!root.mChild)
	{	
		root.mChild = std::make_unique<Node>(element);
	}
	else
	{
		push_front_rec(element, *root.mChild);
	}
}

int LinkedList::pop_front()
{
	if (empty())
	{
		throw std::runtime_error("Empty list");
	}

	--mSize;

	if (!mHead->mChild)
	{
		int element = mHead->mElement;
		mHead = nullptr;
		return element;
	}
	
	return pop_front_rec(*mHead);
}

int LinkedList::pop_front_rec(Node& root)
{
	if (!root.mChild->mChild)
	{
		int element = root.mChild->mElement;
		root.mChild = nullptr;
		return element;
	}

	return pop_front_rec(*root.mChild);
}
