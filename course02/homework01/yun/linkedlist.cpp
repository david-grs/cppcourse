#include <cassert>
#include "linkedlist.h"


LinkedListInt::LinkedListInt(): mSize(0), mHead(nullptr) {}

int LinkedListInt::size() const
{
	return mSize;
}

void LinkedListInt::push(int value)
{
	std::unique_ptr<NodeInt> newNodePtr = std::make_unique<NodeInt>();
	newNodePtr->mData = value;

	newNodePtr->next = std::move(mHead);
	mHead = std::move(newNodePtr);

	mSize++;
}


int LinkedListInt::pop_head()
{
	assert(mSize > 0);

	int head = mHead->mData;
	mHead = std::move(mHead->next);

	mSize--;
	return head;
}

void LinkedListInt::clear()
{
	mSize = 0;
	mHead.reset();
}
