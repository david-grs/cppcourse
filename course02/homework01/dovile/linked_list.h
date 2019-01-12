#include <iostream>

using namespace std;

class LinkedList
{

public:
	LinkedList();
	~LinkedList();

	struct Node
	{
		Node* next{ nullptr };
		int data;
	};

	void Insert(int key);
	void Remove(int key);
	Node* Find(int key);
	const Node* End() const;
	std::size_t Size() const;
	bool Empty() const;

	friend ostream &operator<<(ostream&, LinkedList&);

private:

	void clear();
	Node* find_previous(int k);

	Node* mHead{ nullptr };
	Node* mTail{ nullptr };
	std::size_t mSize = 0;
};

inline ostream &operator<<(ostream &output, LinkedList& linkedList) {
	
	LinkedList::Node* node = new LinkedList::Node;
	
	if (linkedList.mHead)
	{
		output << "LinkedList content:" << endl; 
		for (node = linkedList.mHead; node != 0; node = node->next)
		{
			output << node->data << endl;
		}
	}
	else
	{
		output << "LinkedList is empty" << endl;
	}

	return output;
}

struct LinkedListError : public std::exception
{
	LinkedListError(const char* description) :
		mDescription(description)
	{
	}

	const char* what() const throw ()
	{
		return mDescription;
	}

	const char* mDescription;
};
