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
class LinkedListIterator;

template<typename T>
class LinkedList
{
public:

	LinkedList();
	
	LinkedList(const LinkedList& other);
	
	LinkedList& operator=(LinkedList other);

	void Append(const T& data);

	LinkedListIterator<T> begin();
  	LinkedListIterator<T> end();

	template<typename U>
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList<U>& list);

private:

	std::unique_ptr<Node<T>> mFirst;
	Node<T>* mLast;
	int mSize {};
};

template<typename T>
class LinkedListIterator: public std::iterator<std::input_iterator_tag, T, T, const T*, T>
{
public:
  explicit LinkedListIterator(Node<T>* ptrNode);

  LinkedListIterator& operator++();

  bool operator !=(const LinkedListIterator& other);

  T& operator*();

private:
   Node<T>* mPtrNode;
};

#include "linked_list.cc"
