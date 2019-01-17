//#include "linked_list.h"

template <class T>
void LinkedList<T>::PushBack(T key)
{
	auto newNode = std::make_unique<Node<T>>(key);

	if (mHead)
	{
		Node<T>* node = mHead.get();
		while (node->mNext)
		{
			node = node->mNext.get();
		}
		node->mNext = std::move(newNode);
	}
	else
	{
		mHead = std::move(newNode);
	}
	++mSize;
}

template <class T>
void LinkedList<T>::EraseAt(int position)
{
	if (position >= 0 && position < Size())
	{
		Node<T>* current = mHead.get();
		Node<T>* previous = current;
		while (position > 0)
		{
			previous = current;
			current = current->mNext.get();
			--position;
		}
		previous->mNext = std::move(current->mNext);
		--mSize;
	}
	else
	{
		throw std::out_of_range("Cannot erase element");
	}
}

template <class T>
T& LinkedList<T>::At(int position) const
{
	if (position < Size())
	{
		auto* node = mHead.get();
		while (position > 0)
		{
			node = node->mNext.get();
			--position;
		}
		return node->mData;
	}
	else
	{
		throw std::out_of_range("Could not find the element");
	}
}

template <class T>
std::size_t LinkedList<T>::Size() const
{
	return mSize;
}

template <class T>
bool LinkedList<T>::Empty() const
{
	return Size() == 0;
}

template <class T>
void LinkedList<T>::Clear()
{
	mSize = 0;
	mHead.reset();
}



