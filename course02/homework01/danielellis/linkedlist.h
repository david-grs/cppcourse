#pragma once

#include <memory>
#include <iterator>

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

class Iterator : public std::iterator<std::forward_iterator_tag, int>
{
public:
	Iterator();
	Iterator(LinkedListNode* lln);

	int& operator*();
	Iterator operator++();
	bool operator==(const Iterator& other);
	bool operator!=(const Iterator& other);

private:
	LinkedListNode* mCurrentNode;
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
	Iterator Begin();
	Iterator End();

	LinkedList& swap(LinkedList& ll);
	LinkedList& operator=(LinkedList ll);

private:
	std::unique_ptr<LinkedListNode> mStart;
	int mSize;
	LinkedListNode* mEnd;
};
