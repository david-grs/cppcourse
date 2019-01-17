#include "linkedlist.h"

#include <stdexcept>

Iterator::Iterator(LinkedListNode* lln) : mCurrentNode(lln)
{
}

Iterator::Iterator() : mCurrentNode(nullptr)
{
}

Iterator Iterator::operator++()
{
	mCurrentNode = mCurrentNode->mNext.get();
}

int& Iterator::operator*()
{
	return mCurrentNode->mPayload;
}

bool Iterator::operator==(const Iterator& rhs)
{
	return (this->mCurrentNode == rhs.mCurrentNode);
}

bool Iterator::operator!=(const Iterator& rhs)
{
	return !(*this == rhs);
}

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

LinkedList& LinkedList::swap(LinkedList& ll)
{
	using std::swap;
	swap(this->mSize, ll.mSize);
	swap(this->mStart, ll.mStart);
	swap(this->mEnd, ll.mEnd);
	return *this;
}

LinkedList& LinkedList::operator=(LinkedList ll)
{
	swap(ll);
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

Iterator LinkedList::Begin()
{
	return Iterator(mStart.get());
}

Iterator LinkedList::End()
{
	return Iterator();
}

LinkedListNode::LinkedListNode(int payload)
{
	mPayload = payload;
}

LinkedListNode::LinkedListNode(const LinkedListNode& lln)
{
	mPayload = lln.mPayload;
}

LinkedListNode& LinkedListNode::swap(LinkedListNode& lln)
{
	using std::swap;
	swap(this->mPayload, lln.mPayload);
	swap(this->mNext, lln.mNext);
}

LinkedListNode& LinkedListNode::operator=(const LinkedListNode& lln)
{
	mPayload = lln.mPayload;
	return *this;
}
