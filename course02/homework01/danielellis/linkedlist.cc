#include "linkedlist.h"

#include <stdexcept>

using namespace std;

LinkedList::LinkedList() : mSize(0)
{
}

LinkedList::LinkedList(const LinkedList& ll)
{
	if (ll.Size() > 0)
	{
		shared_ptr<LinkedListNode> last;
		mStart = ll.mStart->Clone(last);
		mEnd = last;
	}
	mSize = ll.Size();
}

int LinkedList::Size() const
{
	return mSize;
}

int& LinkedList::At(int position)
{
	if (position >= Size())
		throw out_of_range("Position out of range of this list");
	return mStart->Retrieve(position);
}

int LinkedList::At(int position) const
{
	if (position >= Size())
		throw out_of_range("Position out of range of this list");
	int result = mStart->Retrieve(position);
	return result;
}

void LinkedList::Append(int payload)
{
	auto newNode = make_shared<LinkedListNode>(payload);
	if (Size() == 0)
	{
		mStart = newNode;
		mEnd = mStart;
	}
	else
	{
		mEnd->mNext = newNode;
		mEnd = newNode;
	}
	mSize++;
}

shared_ptr<LinkedListNode> LinkedListNode::Clone(shared_ptr<LinkedListNode> last)
{
	auto l = make_shared<LinkedListNode>(mPayload);
	if (mNext)
		l->mNext = mNext->Clone(last);
	else
		last = l;
	return l;
}

int& LinkedListNode::Retrieve(int indirectionsLeft)
{
	if (indirectionsLeft > 0)
		return mNext->Retrieve(indirectionsLeft - 1);
	else
		return mPayload;
}

LinkedListNode::LinkedListNode(int payload)
{
	mPayload = payload;
}

LinkedListNode::LinkedListNode(const LinkedListNode& lln)
{
	mPayload = lln.mPayload;
	if (mNext)
		mNext = make_shared<LinkedListNode>(lln);
}
