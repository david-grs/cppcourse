#pragma once

#include <iostream>
#include <memory>

template <class T>
struct Node
{
	explicit Node(T data) :
		mData(data) {}

	std::unique_ptr<Node<T>> mNext;
	T mData;
};

template<class T>
class LinkedList
{
	using NodePointer = typename std::unique_ptr<Node<T>>;

public:
	void PushBack(T key);
	void EraseAt(int position);
	T& At(int position) const;
	std::size_t Size() const;
	bool Empty() const;
	void Clear();

	template <class U>
	friend std::ostream &operator<<(std::ostream&, LinkedList<U>&);

private:
	NodePointer mHead;
	std::size_t mSize = 0;
};

template<class T>
inline std::ostream &operator<<(std::ostream &output, LinkedList<T>& linkedList) {
		
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
