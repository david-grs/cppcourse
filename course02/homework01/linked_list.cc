#include "linked_list.h"

void LinkedList::PushBack(int key)
{
	auto newNode = std::make_unique<Node>(key);

	if (mHead)
	{
		Node* node = mHead.get();
		while (node->mNext)
		{
			node = node->mNext.get();
		}
		node->mNext = std::move(newNode);
	}
	else
	{
		mHead = std::move(newNode);
	}
	
	++mSize;
}

void LinkedList::EraseAt(int position)
{
	if (position < Size())
	{
		Node* current = mHead.get();
		Node* previous = current;
		while (position > 0)
		{
			previous = current;
			current = current->mNext.get();
			--position;
		}
		previous->mNext = std::move(current->mNext);
		--mSize;
	}
	else
	{
		throw std::out_of_range("Cannot erase element");
	}
}

Node& LinkedList::At(int position) const
{
	if (position < Size())
	{
		auto node = mHead.get();
		while (position > 0)
		{
			node = node->mNext.get();
			--position;
		}
		return *node;
	}
	else
	{
		throw std::out_of_range("Could not find the element");
	}
}

std::size_t LinkedList::Size() const
{
	return mSize;
}

bool LinkedList::Empty() const
{
	return Size() == 0;
}

void LinkedList::Clear()
{
	mSize = 0;
	mHead.reset();
}



