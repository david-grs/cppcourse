#pragma once

#include <memory>

template <class T>
class ForwardList
{
public:
	struct Node
	{
		Node(T value, std::unique_ptr<Node> next) :
			mValue(value),
			mNext(std::move(next))
		{}

		T mValue;
		std::unique_ptr<Node> mNext;
	};

	void push_front(const T& value)
	{
		mFirst = std::make_unique<Node>(value, std::move(mFirst));
	}

	class Iterator : public std::iterator<std::forward_iterator_tag, T>
	{
	public:
		Iterator& operator++() { mNode = mNode->mNext.get(); return *this; }
		T& operator*() { return mNode->mValue; }
		bool operator==(Iterator rhs) { return mNode == rhs.mNode; }
		bool operator!=(Iterator rhs) { return !operator==(rhs); }

	private:
		friend class ForwardList;

		explicit Iterator(Node* node) :
			mNode(node)
		{}

		Node* mNode;
	};

	using iterator = Iterator;
	using value_type = T;

	iterator begin() { return Iterator{mFirst.get()}; }
	iterator end() { return Iterator{nullptr}; }

private:
	std::unique_ptr<Node> mFirst;
};
