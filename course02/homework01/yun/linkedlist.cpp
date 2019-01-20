#include <cassert>
#include "linkedlist.h"



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


LinkedListIterator LinkedListIterator::operator++()
{
	if ((*nodePtr)->next){
	nodePtr = &((*nodePtr)->next);
	} else {
		nodePtr = nullptr;
	}
	return nodePtr;
}

LinkedListIterator LinkedListIterator::operator++(int)
{
	LinkedListIterator result(*this);
	++(*this);
	return result;
}

bool LinkedListIterator::operator==(const LinkedListIterator& other)
{
	return nodePtr == other.nodePtr;
}

bool LinkedListIterator::operator!=(const LinkedListIterator& other)
{
	return nodePtr != other.nodePtr;
}
