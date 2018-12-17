#pragma once

#include <memory>

struct LinkedListNode
{
	LinkedListNode() = default;
	LinkedListNode(const LinkedListNode& lln);
	LinkedListNode(int payload);
	std::shared_ptr<LinkedListNode> Clone(std::shared_ptr<LinkedListNode> last);
	int& Retrieve(int indirectionsLeft);

	std::shared_ptr<LinkedListNode> mNext;
	int mPayload;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList& ll);
	int Size() const;
	int& At(int position);
	int At(int position) const;
	void Append(int payload);

private:
	std::shared_ptr<LinkedListNode> mStart;
	int mSize;
	std::shared_ptr<LinkedListNode> mEnd;
};
