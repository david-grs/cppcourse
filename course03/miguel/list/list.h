#include <functional>
#include <memory>
#include <utility>

#ifdef DEBUG
#include <iostream>
#endif

class IntNode
{
public:
	using Data = int;

	explicit IntNode(int data)
	: mData{data}
	{}

	~IntNode()
	{
#ifdef DEBUG
		std::cout << "~Node(" << mData << ")" << std::endl;
#endif
	}

	inline int Get() const { return mData; }
	inline void Set(int data) { mData = data; }

private:
	Data mData;
};

struct ListNode : public IntNode
{
	ListNode(IntNode::Data data)
	: IntNode{data}, mNext{nullptr}
	{}

	std::unique_ptr<ListNode> mNext;
};

class LinkedListInt
{
public:

	LinkedListInt() : mFirst{nullptr} {} 
	~LinkedListInt() { mFirst.reset(); }

	std::unique_ptr<ListNode>& First() { return mFirst; }

	void InsertAfter(std::unique_ptr<ListNode>& position, int i);
	void InsertFront(int  i);

	void RemoveAfter(std::unique_ptr<ListNode>& ptr);

	void RemoveFront();

	static std::unique_ptr<ListNode>& Next(const std::unique_ptr<ListNode>& node);

	void Clear() { mFirst.reset(); } 

	void ApplyAll(const std::function<void(std::unique_ptr<ListNode>&)> lambda) { ApplyAllImpl(mFirst, lambda); }

	class RemoveException {};
private:

	void ApplyAllImpl(std::unique_ptr<ListNode>& ptr, const std::function<void(std::unique_ptr<ListNode>&)>& lambda);

	std::unique_ptr<ListNode> mFirst = nullptr;
};
