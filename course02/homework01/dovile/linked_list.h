#pragma once

#include <iostream>
#include <memory>

struct Node
{
	explicit Node(int data) :
		mData(data) {}

	std::unique_ptr<Node> mNext;
	int mData;
};

class LinkedList
{
	using NodePointer = typename std::unique_ptr<Node>;

public:
	void PushBack(int key);
	void EraseAt(int position);
	Node& At(int position) const;
	std::size_t Size() const;
	bool Empty() const;
	void Clear();

	friend std::ostream &operator<<(std::ostream&, LinkedList&);

private:
	NodePointer mHead;
	std::size_t mSize = 0;
};

inline std::ostream &operator<<(std::ostream &output, LinkedList& linkedList) {
		
	if (linkedList.mHead)
	{
		auto* node = linkedList.mHead.get();
		output << "LinkedList content:\n"; 
		while (node)
		{
			output << node->mData << std::endl;
			node = node->mNext.get();
		}
	}
	else
	{
		output << "LinkedList is empty.";
	}
	return output;
}
