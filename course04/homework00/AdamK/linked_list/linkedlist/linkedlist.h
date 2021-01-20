#pragma once

#include <memory>

struct Node
{
	Node(int element) : mElement(element) {};

	int mElement = 0;
	std::unique_ptr<Node> mChild = nullptr;
};

class LinkedList
{
public:
	bool empty() const { return mSize == 0; }
	int size() const { return mSize; }

	void push_front(int element);
	int pop_front();

private:
	void push_front_rec(int element, Node& root);
	int pop_front_rec(Node& root);

private:
	std::size_t mSize = 0;
	std::unique_ptr<Node> mHead = nullptr;
};
