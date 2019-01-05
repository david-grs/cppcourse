#include "linkedlist.h"

#include <stdexcept>

LinkedList::LinkedList() : mSize(0)
{
}

LinkedList::LinkedList(const LinkedList& ll)
{
	mSize = ll.Size();
	if (mSize > 0)
	{
		mStart.reset(new LinkedListNode(*ll.mStart));
		LinkedListNode* ourNode = mStart.get();
		LinkedListNode* theirNode = ll.mStart.get();
		for (int i = 0; i < mSize - 1; ++i)
		{
			ourNode->mNext.reset(new LinkedListNode(*(theirNode->mNext)));
			ourNode = ourNode->mNext.get();
			theirNode = theirNode->mNext.get();
		}
		mEnd = ourNode;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& ll)
{
	mSize = ll.Size();
	if (mSize > 0)
	{
		mStart.reset(new LinkedListNode(*ll.mStart));
		LinkedListNode* ourNode = mStart.get();
		LinkedListNode* theirNode = ll.mStart.get();
		for (int i = 0; i < mSize - 1; ++i)
		{
			ourNode->mNext.reset(new LinkedListNode(*(theirNode->mNext)));
			ourNode = ourNode->mNext.get();
			theirNode = theirNode->mNext.get();
		}
		mEnd = ourNode;
	}
	return *this;
}

int LinkedList::Size() const
{
	return mSize;
}

int& LinkedList::At(int position)
{
	if (position >= Size())
		throw std::out_of_range("Position out of range of this list");
	LinkedListNode* requiredNode = mStart.get();
	for (int i = 0; i < position; ++i)
	{
		requiredNode = requiredNode->mNext.get();
	}
	return requiredNode->mPayload;
}

int LinkedList::At(int position) const
{
	if (position >= Size())
		throw std::out_of_range("Position out of range of this list");
	LinkedListNode* requiredNode = mStart.get();
	for (int i = 0; i < position; ++i)
	{
		requiredNode = requiredNode->mNext.get();
	}
	return requiredNode->mPayload;
}

void LinkedList::Append(int payload)
{
	if (Size() == 0)
	{
		mStart.reset(new LinkedListNode(payload));
		mEnd = mStart.get();
	}
	else
	{
		mEnd->mNext.reset(new LinkedListNode(payload));
		mEnd = mEnd->mNext.get();
	}
	mSize++;
}

LinkedListNode::LinkedListNode(int payload)
{
	mPayload = payload;
}

LinkedListNode::LinkedListNode(const LinkedListNode& lln)
{
	mPayload = lln.mPayload;
}

LinkedListNode& LinkedListNode::operator=(const LinkedListNode& lln)
{
	mPayload = lln.mPayload;
	return *this;
}
