#pragma once
#include <iterator>
#include <memory>


struct NodeInt
{
	NodeInt(): mData(0), next(nullptr) {}
	int mData;
	std::unique_ptr<NodeInt> next;
};


class LinkedListIterator
: public std::iterator<std::forward_iterator_tag, NodeInt*>
{
	friend class LinkedListInt;

public:
	int operator*() { return ((*nodePtr)->mData);}

	LinkedListIterator operator++();
	LinkedListIterator operator++(int);

	bool operator==(const LinkedListIterator& other);

	bool operator!=(const LinkedListIterator& other);

private:
	LinkedListIterator() : nodePtr(nullptr) {}
	LinkedListIterator(std::unique_ptr<NodeInt>* newNodePtr) : nodePtr(newNodePtr){}

	std::unique_ptr<NodeInt>* nodePtr;
};


class LinkedListInt
{
public:
	LinkedListInt(): mSize(0), mHead(nullptr) {}

	int size() const;

	void push(int value);

	int pop_head();

	void clear();

	LinkedListIterator begin() {return &mHead;}

	LinkedListIterator end() {return nullptr;}

private:
	int mSize;

	std::unique_ptr<NodeInt> mHead;
};
