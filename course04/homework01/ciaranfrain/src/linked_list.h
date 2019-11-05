#pragma once

#include <memory>

struct Node
{
	using Ptr = std::shared_ptr<Node>;

	Node(int value): mValue(value) {};
	Node(int value, Ptr next): mValue(value), mNext(next) {};
	int mValue;
	Ptr mNext; 
};

class LinkedList
{
public:
	int front() const;
	int back() const;
	int at(const std::size_t) const;

	void push_back(const int);
	void push_front(const int);
	void insert(const int, const std::size_t);

	void erase(const std::size_t);

	std::size_t size() const { return mSize; }
	bool empty() const { return mSize == 0; }

private:
	Node::Ptr NodeAt(const std::size_t) const;
	void CheckRange(const std::size_t) const;

	Node::Ptr mFront; 
	Node::Ptr mBack; 
	std::size_t mSize = 0;
};

