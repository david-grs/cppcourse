#pragma once

#include <memory>

template <class T>
class LinkedList
{
public:
	using value_type = T;

	struct Node
	{
		Node(T value, std::unique_ptr<Node> next) :
			mValue(value),
			mNext(std::move(next))
		{}

		T mValue;
		std::unique_ptr<Node> mNext;
	};

	class Iterator : public std::iterator<std::forward_iterator_tag, T>
	{
	public:
		Iterator& operator++() { mNode = mNode->mNext.get(); return *this; }
		T& operator*() { return mNode->mValue; }

		bool operator!=(const Iterator& other) const
		{
			return mNode != other.mNode;
		}

	private:
		friend class LinkedList;

		explicit Iterator(Node* node) :
			mNode(node)
		{}

		Node* mNode;
	};

	void push_front(const T& value)
	{
		mFirst = std::make_unique<Node>(value, std::move(mFirst));
	}

	Iterator begin() { return Iterator{mFirst.get()}; }
	Iterator end() { return Iterator{nullptr}; }

private:
	std::unique_ptr<Node> mFirst;
};
