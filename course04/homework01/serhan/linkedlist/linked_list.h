#pragma once

#include <memory>

struct Node
{
	int mData;
	std::unique_ptr<Node> mNext;

	Node(int data) : mData{data}, mNext{nullptr} {}
};

class linked_list
{
public:
	linked_list() : mHead{nullptr} {};

	~linked_list() { reset(); }

	void push_front(int data);
	void pop_front();
	void reset();
	void reverse();
	int at(const size_t& index);
	int size() { return mSize; };

	friend std::ostream &operator<<(std::ostream &os, const linked_list &list);

private:
	std::unique_ptr<Node> mHead;
	std::size_t mSize = 0;
};
