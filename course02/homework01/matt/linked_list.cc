
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
		std::cout << mFirst->mData << std::endl;
		mLast = mFirst.get();
	}
	else
	{
		mLast->mNext = std::make_unique<Node<T>>(data);
		mLast = mLast->mNext.get();
	}

	 mSize++;
}

