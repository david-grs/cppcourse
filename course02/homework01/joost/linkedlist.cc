#include "linkedlist.h"
#include <iostream>
#include <cassert>

LinkedListInt::LinkedListInt():
	mHead(NULL),
	mSize(0)
{}

int LinkedListInt::size() const
{
	return mSize;
}

void LinkedListInt::append(int value)
{
	Node* last = mHead;
	if( last != NULL )
	{
		while( last->next != NULL )
		{
			last = last->next;
		}
		last->next = new Node();
		last->next->value = value;
	} else {
		mHead = new Node();
		mHead->value = value;
	}
	mSize++;
}

int LinkedListInt::pop_front()
{
	assert(mSize > 0);
	Node* oldhead = mHead;
	mHead = mHead->next;
	int output = oldhead->value;
	delete oldhead;
	mSize--;
	return output;
}

void LinkedListInt::clear()
{
	mHead = NULL;
	mSize = 0;
}
