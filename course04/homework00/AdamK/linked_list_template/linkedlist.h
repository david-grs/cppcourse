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

template <class T> struct IsNonInteger { static constexpr bool value = true; };
template <> struct IsNonInteger<int> { static constexpr bool value = false; };
template <> struct IsNonInteger<long> { static constexpr bool value = false; };

template <class T>
struct Node
{
	Node(T element) : mElement(element) {};

	T mElement;
	std::unique_ptr<Node> mChild = nullptr;
};

template <class T, class Logger>
class LinkedList
{
public:
	static_assert(!IsNonInteger<T>::value, "T needs to be integer. Only integer master race allowed.");

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
