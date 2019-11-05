#include "linked_list.h"
#include <exception>

Node::Ptr LinkedList::NodeAt(const std::size_t index) const
{
	CheckRange(index);

	Node::Ptr node = mFront;
	for (std::size_t i=0; i < index ; i++)
		node = node->mNext;
	return node;
}

void LinkedList::CheckRange(const std::size_t index) const
{
	if (index+1 > mSize)
		throw std::out_of_range("No node at index");
}

int LinkedList::front() const
{
	CheckRange(0);
	return mFront->mValue;
}

int LinkedList::back() const
{
	CheckRange(0);
	return mBack->mValue;
}

int LinkedList::at(const std::size_t index) const
{
	CheckRange(index);
	return NodeAt(index)->mValue;
}

void LinkedList::push_back(const int value)
{
	auto node = std::make_shared<Node>(value);
	if (empty())
		mFront = mBack = node;
	else
	{
		mBack->mNext = node;
		mBack = node;
	}


	mSize++;
}

void LinkedList::push_front(const int value)
{
	if (empty())
		mFront = mBack = std::make_shared<Node>(value);
	else
		mFront = std::make_shared<Node>(value, mFront);

	mSize++;
}

void LinkedList::insert(const int value, const std::size_t index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		CheckRange(index);
		Node::Ptr prevNode = NodeAt(index-1);
		prevNode->mNext = std::make_shared<Node>(value, prevNode->mNext);
		mSize++;
	}
}

void LinkedList::erase(const std::size_t index)
{
	CheckRange(index);

	if (index == 0)
		mFront = mFront->mNext;
	else
	{
		Node::Ptr prevNode = NodeAt(index-1);
		prevNode->mNext = prevNode->mNext->mNext;
	}

	mSize--;
}

