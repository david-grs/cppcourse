#pragma once

#include <memory>

template <class T>
class ForwardList
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

	void push_front(const T& value)
	{
		mFirst = std::make_unique<Node>(value, std::move(mFirst));
	}

	struct Iterator : public std::iterator<std::forward_iterator_tag, T>
	{
		explicit Iterator(Node* node) :
			mNode(node)
		{}

		Iterator operator++() { mNode = mNode->mNext.get(); return *this; }
		T& operator*() { return mNode->mValue; }
		bool operator!=(Iterator other) const { return mNode != other.mNode; }

		Node* mNode;
	};

	using iterator = Iterator;

	iterator begin() { return iterator{mFirst.get()}; }
	iterator end() { return iterator{nullptr}; }

private:
	std::unique_ptr<Node> mFirst;
};
