#include "list.h"

void LinkedListInt::InsertAfter(std::unique_ptr<ListNode>& position, int i)
{
	std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>(i);
	newNode->mNext = std::move(position->mNext);
	position->mNext = std::move(newNode);
}

void LinkedListInt::InsertFront(int  i)
{
	std::unique_ptr<ListNode> node = std::make_unique<ListNode>(i);
	node->mNext = std::move(mFirst);
	mFirst = std::move(node);
}

void LinkedListInt::RemoveAfter(std::unique_ptr<ListNode>& ptr)
{
	if (ptr && ptr->mNext)
		ptr->mNext = std::move(ptr->mNext->mNext);
	else 
		throw RemoveException();
}

void LinkedListInt::RemoveFront()
{
	if (mFirst)
		mFirst = std::move(mFirst->mNext);
	else 
		throw RemoveException();
}

std::unique_ptr<ListNode>& LinkedListInt::Next(const std::unique_ptr<ListNode>& node) { return node->mNext; }

void LinkedListInt::ApplyAllImpl(std::unique_ptr<ListNode>& ptr, const std::function<void(std::unique_ptr<ListNode>&)>& lambda)
{
	if (ptr)
	{
		lambda(ptr);
		ApplyAllImpl(ptr->mNext, lambda);
	}
}
