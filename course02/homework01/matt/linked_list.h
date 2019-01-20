#include <memory>

template<typename T>
struct Node
{
	Node(const T& t)
	: mData(t)
	{};

	T mData;
	std::unique_ptr<Node<T>> mNext;
};

template<typename T>
class LinkedList
{
public:

	LinkedList();
	
	LinkedList(const LinkedList& other);
	
	LinkedList& operator=(LinkedList other);

	void Append(const T& data);

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
	{
	    Node<T>* ptrNode = list.mFirst.get();
	    while(ptrNode != nullptr)
	    {
	        stream << ptrNode->mData << ", ";
	        ptrNode = ptrNode->mNext.get();
	    }
	    
		return stream;
	}

private:
	std::unique_ptr<Node<T>> mFirst;
	Node<T>* mLast;
	int mSize {};
};

#include "linked_list.cc"
