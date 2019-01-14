#pragma once
#include <memory>


struct NodeInt
{
	int mData;
	std::unique_ptr<NodeInt> next;
};


class LinkedListInt
{
public:
	LinkedListInt();

	int size() const;

	void push(int value);

	int pop_head();

	void clear();

private:
	int mSize;

	std::unique_ptr<NodeInt> mHead;
};
