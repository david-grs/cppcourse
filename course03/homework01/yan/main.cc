#include <iostream>
#include <memory>

struct Node
{
	explicit Node(int value): mData(value) {}

	int mData;
	std::unique_ptr<Node> mNext;
};

class LinkedListInt
{
public:
	LinkedListInt() = default;

	int At(size_t position)
	{
		Node& nodeAtPosition = GetNext(*mHead, position);
		return nodeAtPosition.mData;
	}

	void Insert(size_t position, int value)
	{
		auto newNode = std::make_unique<Node>(value);

		if (position == 0)
		{
			newNode->mNext = std::move(mHead);
			mHead = std::move(newNode);
		}
		else
		{
			Node& prevNode = GetNext(*mHead, position - 1);
			newNode->mNext = std::move(prevNode.mNext);
			prevNode.mNext = std::move(newNode);
		}
		mSize += 1;
	}

	void Insert(int value)
	{
		Insert(0, value);
	}

	size_t Size()
	{
		return mSize;
	}

private:
	Node& GetNext(Node& node, size_t position)
	{
		if (position == 0)
			return node;

		if (!node.mNext)
			throw std::out_of_range("End of list reached.");

		return GetNext(*node.mNext, --position);
	}

	std::unique_ptr<Node> mHead;
	size_t mSize = 0;
};


int main()
{
	LinkedListInt a;
	a.Insert(1);
	a.Insert(2);
	a.Insert(2, 5);
	std::cout << a.Size() << std::endl;
	for (size_t i=0; i < a.Size(); ++i)
		std::cout << a.At(i);
	std::cout << std::endl;

}
