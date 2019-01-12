#pragma once

#include <memory>

class LinkedListNode
{
public:
	LinkedListNode() = default;
	LinkedListNode(const LinkedListNode& lln);
	LinkedListNode(int payload);

	LinkedListNode& swap(LinkedListNode& lln);
	LinkedListNode& operator=(const LinkedListNode& lln);

	std::unique_ptr<LinkedListNode> mNext;
	int mPayload;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList& ll);
	int Size() const;
	int& At(int position);
	int At(int position) const;
	void Append(int payload);

	LinkedList& swap(LinkedList& ll);
	LinkedList& operator=(LinkedList ll);

private:
	std::unique_ptr<LinkedListNode> mStart;
	int mSize;
	LinkedListNode* mEnd;
};
