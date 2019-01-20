
// Linked List
#include <algorithm>

template<typename T>
LinkedList<T>::LinkedList() {}
	 
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	 Node<T>* node = other.mFirst.get();
	 while(node != nullptr)
		  {
				Append(node->mData);
				node = node->mNext.get();
		  }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> other)
{
	 std::swap(this->mFirst, other.mFirst);
	this->mSize = other.mSize;	 

	return *this;
}

template<typename T>
void LinkedList<T>::Append(const T& data)
{
	 if(mFirst==nullptr)
	 {
		mFirst = std::make_unique<Node<T>>(data);
		mLast = mFirst.get();
	}
	else
	{
		mLast->mNext = std::make_unique<Node<T>>(data);
		mLast = mLast->mNext.get();
	}

	 mSize++;
}

//Linked List Iterator

template<typename T>
LinkedListIterator<T> LinkedList<T>::begin()
{
  return LinkedListIterator<T>{mFirst.get()};
}

template<typename T>
LinkedListIterator<T> LinkedList<T>::end()
{
  return LinkedListIterator<T>{mLast->mNext.get()};
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& list)
{
	Node<T>* ptrNode = list.mFirst.get();
	while(ptrNode != nullptr)
	{
		stream << ptrNode->mData << ", ";
		ptrNode = ptrNode->mNext.get();
	}

	return stream;
}

template<typename T>
LinkedListIterator<T>::LinkedListIterator(Node<T>* ptrNode) : mPtrNode(ptrNode){}

template<typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator++()
{
	mPtrNode = mPtrNode->mNext.get();
}

template<typename T>
bool LinkedListIterator<T>::operator !=(const LinkedListIterator& other)
{
   return mPtrNode != other.mPtrNode;
}

template<typename T>
T& LinkedListIterator<T>::operator*()
{
   return mPtrNode->mData;
}
