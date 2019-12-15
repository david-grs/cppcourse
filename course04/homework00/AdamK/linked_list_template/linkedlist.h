#pragma once

#include <iostream>
#include <memory>
#include <type_traits>

// policy
template <class T>
class Cout
{
public:
	bool operator()(const T& element) const
	{
		std::cout << "---";
		std::cout << element;
		std::cout << "---" << std::endl;
		return true;
	}
};

template <class T> struct IsNotLong { static constexpr bool value = true; };
template <> struct IsNotLong<long> { static constexpr bool value = false; };

template <class T, class... Args>
struct Node
{
	Node(const T& element) : mElement(element) {};
	Node(Args&&... args) : mElement(std::forward<Args>(args)...) {};

	T mElement;
	std::unique_ptr<Node> mChild = nullptr;
};

template <class T, class Logger>
class LinkedList
{
public:
	static_assert(IsNotLong<T>::value, "T can not be long. Just because.");

	bool empty() const { return mSize == 0; }
	size_t size() const { return mSize; }

	void push_front(const T& element)
	{
		Logger{}(element);

		if (empty())
		{
			mHead = std::make_unique<Node<T>>(element);
		}
		else
		{
			push_front_rec(element, *mHead);
		}
		++mSize;
	}

	template<class... Args> 
	T& emplace_front(Args&&... args)
	{

		if (empty())
		{
			mHead = std::make_unique<Node<T>>(std::forward<Args>(args)...);
			Logger{}(mHead->mElement);
			++mSize;
			return mHead->mElement;
		}
		else
		{
			return emplace_front_rec(*mHead, std::forward<Args>(args)...);
		}
	}

	T pop_front()
	{
		if (empty())
		{
			throw std::runtime_error("Empty list");
		}

		--mSize;

		if (!mHead->mChild)
		{
			T element = mHead->mElement;
			mHead = nullptr;
			Logger{}(element);
			return element;
		}

		return pop_front_rec(*mHead);
	}

private:
	void push_front_rec(const T& element, Node<T>& root)
	{
		if (!root.mChild)
		{       
			root.mChild = std::make_unique<Node<T>>(element);
		}
		else
		{
			push_front_rec(element, *root.mChild);
		}
	}

	template<class... Args>
	T& emplace_front_rec(Node<T>& root, Args&&... args)
	{
		if (!root.mChild)
		{       
			root.mChild = std::make_unique<Node<T>>(std::forward<Args>(args)...);
			Logger{}(root.mChild->mElement);
			++mSize;
			return root.mChild->mElement;
		}
		else
		{
			return emplace_front_rec(*root.mChild, std::forward<Args>(args)...);
		}
	}

	T pop_front_rec(Node<T>& root)
	{
		if (!root.mChild->mChild)
		{
			T element = root.mChild->mElement;
			root.mChild = nullptr;
			Logger{}(element);
			return element;
		}

		return pop_front_rec(*root.mChild);
	}

private:
	std::size_t mSize = 0;
	std::unique_ptr<Node<T>> mHead = nullptr;
};
