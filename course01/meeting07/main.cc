#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <cstring>

template <class T, std::size_t N>
class Array
{
public:
	T* begin() { return &mValues[0]; }
	T* end() { return &mValues[0] + N; }

	T mValues[N];
};

template <class T>
class LinkedList
{
	struct Node
	{
		Node(const T& value) : mValue(value) {}
		Node(const T& value, std::unique_ptr<Node>&& next) : 
			mValue(value),
			mNext(std::move(next))
		{}

		T mValue;
		std::unique_ptr<Node> mNext = nullptr;
	};

public:
	class Iterator : public std::iterator<std::forward_iterator_tag, T>
	{
	public:
		T& operator*() { return mNode->mValue; }
		Iterator& operator++() { mNode = mNode->mNext.get(); return *this; }

		bool operator==(Iterator it) const { return mNode == it.mNode; }
		bool operator!=(Iterator it) const { return !(*this == it); }

	private:
		friend class LinkedList<T>;

		explicit Iterator(Node* node) :
			mNode(node)
		{}

		Node* mNode;
	};

	Iterator begin() { return Iterator{mHead.get()}; }
	Iterator end() { return Iterator{nullptr}; }

	void push_front(const T& value)
	{
		if (!mHead)
		{
			mHead = std::make_unique<Node>(value);
		}
		else
		{
			mHead = std::make_unique<Node>(value, std::move(mHead));
		}
	}

private:
	std::unique_ptr<Node> mHead;
};

int main()
{
	LinkedList<int> li;
	li.push_front(3);
	li.push_front(2);
	li.push_front(1);
	li.push_front(0);

	for (int i : li)
	{
		std::cout << i << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	auto it = std::find(li.begin(), li.end(), 2);
	std::cout << "found: " << *it << std::endl;

	std::cout << "sum: " << std::accumulate(li.begin(), li.end(), 0) << std::endl;


	Array<int, 3> array{0,1,2};

	for (int i : array)
		std::cout << i << std::endl;
}

#if 0
struct Matcher
{
	bool operator()(const char* str) const
	{
		return mStr == str;
	}

	std::string mStr;
};

int main(int argc, char** argv)
{
	Matcher matcher{argv[1]};
	const int foo = std::count_if(argv + 2, argv + argc, matcher);
	
	std::cout << foo << std::endl;

	return 0;
}

#endif
