#pragma once
#include <array>
#include <stdexcept>
#include <memory>

struct Node
{
	int value;
	Node* next;
};

class LinkedListInt
{
public:
	LinkedListInt();
	//LinkedList(IteratorInt);
	
	int size() const; // time complexity = 1
	void append(int value); // time complexity = o*n
	int pop_front(); // time complexity = 1
	void clear(); // time complexity = 1

private:
	Node* mHead;
	std::size_t mSize; // how many items are in the vector
};


