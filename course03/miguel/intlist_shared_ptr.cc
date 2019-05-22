#include <iostream>
#include <functional>
#include <memory>
#include <utility>

class Node
{
public:

	using Data = int;

	explicit Node(int data)
	: mData{data}
	{}

	~Node()
	{
		std::cout << "~Node(" << mData << ")" << std::endl;
	}

	inline int Get() const { return mData; }
	inline void Set(int data) { mData = data; }

private:
	int mData;
};

struct ListNode : public Node
{
	using Node::Data;

	ListNode(Data data)
	: Node{data}, mNext{nullptr}
	{}

	std::shared_ptr<ListNode> mNext;
};

class LinkedListInt
{
public:

	LinkedListInt() : mFirst{nullptr} {} 
	~LinkedListInt() { mFirst.reset(); }

	std::shared_ptr<ListNode> Front() { return mFirst; }

	void InsertAfter(std::shared_ptr<ListNode>& ptr, std::shared_ptr<ListNode>& node)
	{
		node->mNext = ptr->mNext;
		ptr->mNext = node;
	}

	void InsertBeginning(std::shared_ptr<ListNode> node)
	{
		if (mFirst)
		{
			InsertAfter(node, mFirst);
		}
		mFirst = node;
	}

	void RemoveAfter(std::shared_ptr<ListNode> ptr)
	{
		if (ptr && ptr->mNext) ptr->mNext = ptr->mNext->mNext;
	}

	void RemoveFront() { mFirst = mFirst->mNext; }

	void Clear() { mFirst.reset(); } 

	void ApplyAll(const std::function<void(std::shared_ptr<ListNode>&)> lambda)
	{
		ApplyAllImpl(mFirst, lambda);
	}

private:

	void ApplyAllImpl(std::shared_ptr<ListNode>& ptr, const std::function<void(std::shared_ptr<ListNode>&)>& lambda)
	{
		if (ptr)
		{
			lambda(ptr);
			ApplyAllImpl(ptr->mNext, lambda);
		}
	}

	std::shared_ptr<ListNode> mFirst = nullptr;
};

int main()
{

	{
		LinkedListInt lli;

		auto one = std::make_shared<ListNode>(1);
		auto two = std::make_shared<ListNode>(2);
		auto three = std::make_shared<ListNode>(3);

		lli.InsertBeginning(three);
		lli.InsertBeginning(one);

		lli.ApplyAll([](auto& node){std::cerr << node->Get() << std::endl;});

		lli.InsertAfter(one, two);

		lli.ApplyAll([](auto& node){std::cerr << node->Get() << std::endl;});

		lli.RemoveAfter(two);
		lli.ApplyAll([](auto& node){std::cerr << node->Get() << std::endl;});

		lli.RemoveAfter(one);
		lli.ApplyAll([](auto& node){std::cerr << node->Get() << std::endl;});
		
		lli.RemoveFront();
		lli.ApplyAll([](auto& node){std::cerr << node->Get() << std::endl;});
	}
}


