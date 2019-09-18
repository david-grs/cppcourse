#pragma once

#include <iostream>
#include <memory>

template<class T>
struct Node
{
	explicit Node(T data) :
		mData(data) {}

	std::unique_ptr<Node<T>> mNext;
	T mData;
};

template<class T>
class NodeIterator : std::iterator<std::forward_iterator_tag, T>
{
public:
	explicit NodeIterator(Node<T>* node) 
		: mNode(node) {}
	
	NodeIterator& operator=(Node<T> node)
	{
		this->mNode = node;
		return *this;
	}

	NodeIterator& operator++()
	{
		if (mNode)
			mNode = mNode->mNext.get();

		return *this;
	}

	bool operator!=(const NodeIterator& iterator)
	{
		return mNode != iterator.mNode;
	}

	T operator*()
	{
		return mNode->mData;
	}

private:
	Node<T>* mNode;
};


template<class T>
class LinkedList
{
	using NodePointer = typename std::unique_ptr<Node<T>>;
	typedef NodeIterator<T> iterator;

public:
	void PushBack(T key);
	void EraseAt(int position);
	T& At(int position) const;
	std::size_t Size() const;
	bool Empty() const;
	void Clear();
	iterator begin() { return iterator(mHead.get()); }
	iterator end() { return iterator(nullptr); }

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
