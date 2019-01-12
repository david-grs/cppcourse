#include "linked_list.h"
#include <exception>

using Node = LinkedList::Node;

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::Insert(int key)
{
	Node* node = new Node;
	node->data = key;
	
	if (mHead)
	{
		mTail->next = node;
		mTail = mTail->next;
	}
	else
	{
		mHead = node;
		mTail = node;
	}
	++mSize;
#ifndef NDEBUG
	cout << "Inserted node: " << node->data << endl;
#endif // !NDEBUG
}

void LinkedList::Remove(int key)
{
	Node* current = mHead;
	Node* previous = nullptr;
	while (current)
	{
		if (current->data == key)
		{
			if (current == mHead)
			{
				mHead = mHead->next;
			}
			else
			{
				previous->next = current->next;
			}
			--mSize;
#ifndef NDEBUG
			cout << "Removed node: " << current->data << endl;
#endif // !NDEBUG
			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}	
	throw LinkedListError("Element was not found");
}

Node* LinkedList::Find(int key)
{
	Node* node = mHead;
	while (node)
	{
		if (node->data == key)
		{
			return node;
		}
		node = node->next;
	}
	return End();
}

const Node* LinkedList::End() const
{
	return mTail;
}

bool LinkedList::Empty() const
{
	return mSize == 0;
}

std::size_t LinkedList::Size() const
{
	return mSize;
}

void LinkedList::clear()
{
	Node* node = mHead;
	while (node)
	{
		Node* nodeToDelete = node;
		node = node->next;

#ifndef NDEBUG
		cout << "Deleting node: " << nodeToDelete->data << endl;
#endif // !NDEBUG
		delete nodeToDelete;
	}
}


