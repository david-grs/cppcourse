#pragma once

#include <cstddef>
#include <cassert>
#include <iterator>
#include <memory>

template<typename T>
class List
{
private:
	struct Node
	{
		Node(const T& data);

		T data;

		std::unique_ptr<Node> next;
		Node* prev;
	};

public:	
	template<typename iterator_type, typename iterator_value_type>
	class IteratorBase : public std::iterator<std::bidirectional_iterator_tag, iterator_value_type>
	{
	protected:
		IteratorBase(const List<T>* owner, Node* node);

	public:
		iterator_type operator++(int);
		iterator_type& operator++();
		iterator_type operator--(int);
		iterator_type& operator--();

		iterator_value_type& operator*() const;
		iterator_value_type* operator->() const;

		bool operator==(const iterator_type& second) const;
		bool operator!=(const iterator_type& second) const;

	protected:
		const List<T>* mOwner;
		Node* mNode;
	};

	class Iterator : public IteratorBase<Iterator, T>
	{
	protected:
		Iterator(const List<T>* owner, Node* node);
		friend List<T>;
	};

	class ConstIterator : public IteratorBase<ConstIterator, const T>
	{
	protected:
		ConstIterator(const List<T>* owner, Node* node);
		friend List<T>;

	public:
		ConstIterator(const Iterator& iter);
	};

	using value_type = T;
	using allocator_type = std::allocator<T>;
	using reference = T & ;
	using const_reference = const T&;
	using pointer = T * ;
	using const_pointer = const T*;
	using iterator = Iterator;
	using const_iterator = ConstIterator;
	using size_type = size_t;

	List();
	List(const List& second);
	~List();

	List& operator=(List<T> second);

	void insert(Iterator position, const T& value);
	void push_front(const T& value);
	void push_back(const T& value);

	void erase(Iterator position);
	void pop_front();
	void pop_back();

	void clear();

	Iterator begin();
	ConstIterator begin() const;
	ConstIterator cbegin() const;

	Iterator end();
	ConstIterator end() const;
	ConstIterator cend() const;

	std::size_t size() const;
	bool empty() const;

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

private:
	void insert_first(const T& value);
	void insert_begin(const T& value);
	void insert_end(const T& value);
	void insert_before_position(const T& value, Node* position);

	void erase_last();
	void erase_begin();
	void erase_end();
	void erase_at_position(Node* node);

	std::unique_ptr<Node> mBegin;
	Node* mEnd;

	std::size_t mSize;
};

template<typename T>
List<T>::Node::Node(const T& data) :
	data(data),
	next(nullptr),
	prev(nullptr)
{ }

template<typename T>
template<typename iterator_type, typename iterator_value_type>
List<T>::IteratorBase<iterator_type, iterator_value_type>::IteratorBase(const List<T>* owner, List<T>::Node* node) :
	mOwner(owner),
	mNode(node)
{ }

template<typename T>
List<T>::Iterator::Iterator(const List<T>* owner, List<T>::Node* node) :
	List<T>::IteratorBase<List<T>::Iterator, T>::IteratorBase(owner, node)
{ }

template<typename T>
List<T>::ConstIterator::ConstIterator(const List<T>* owner, List<T>::Node* node) :
	List<T>::IteratorBase<List<T>::ConstIterator, const T>::IteratorBase(owner, node)
{ }

template<typename T>
List<T>::ConstIterator::ConstIterator(const List<T>::Iterator& iter) :
	List<T>::IteratorBase<List<T>::ConstIterator, const T>::IteratorBase(iter.mOwner, iter.mNode)
{ }

template<typename T>
template<typename iterator_type, typename iterator_value_type>
typename iterator_type List<T>::IteratorBase<iterator_type, iterator_value_type>::operator++(int)
{
	iterator_type copy(mOwner, mNode);
	operator++();
	return copy;
}

template<typename T>
template<typename iterator_type, typename iterator_value_type>
typename iterator_type& List<T>::IteratorBase<iterator_type, iterator_value_type>::operator++()
{
	mNode = mNode ? mNode->next.get() : mOwner->mBegin.get();
	return static_cast<iterator_type&>(*this);
}

template<typename T>
template<typename iterator_type, typename iterator_value_type>
typename iterator_type List<T>::IteratorBase<iterator_type, iterator_value_type>::operator--(int)
{
	iterator_type copy(mOwner, mNode);
	operator--();
	return copy;
}

template<typename T>
template<typename iterator_type, typename iterator_value_type>
typename iterator_type& List<T>::IteratorBase<iterator_type, iterator_value_type>::operator--()
{
	mNode = mNode ? mNode->prev : mOwner->mEnd;
	return static_cast<iterator_type&>(*this);
}

template<typename T>
template<typename iterator_type, typename iterator_value_type>
iterator_value_type& List<T>::IteratorBase<iterator_type, iterator_value_type>::operator*() const
{
	return mNode->data;
}

template<typename T>
template<typename iterator_type, typename iterator_value_type>
iterator_value_type* List<T>::IteratorBase<iterator_type, iterator_value_type>::operator->() const
{
	return &(mNode->data);
}

template<typename T>
template<typename iterator_type, typename iterator_value_type>
bool List<T>::IteratorBase<iterator_type, iterator_value_type>::operator==(const iterator_type& second) const
{
	return mNode == second.mNode;
}

template<typename T>
template<typename iterator_type, typename iterator_value_type>
bool List<T>::IteratorBase<iterator_type, iterator_value_type>::operator!=(const iterator_type& second) const
{
	return mNode != second.mNode;
}

template<typename T>
List<T>::List() :
	mBegin(nullptr),
	mEnd(nullptr),
	mSize(0)
{ }

template<typename T>
List<T>::List(const List<T>& second) :
	List()
{
	for (const auto& element : second)
		push_back(element);
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
List<T>& List<T>::operator=(List<T> second)
{
	clear();

	std::swap(this->mBegin, second.mBegin);
	std::swap(this->mEnd, second.mEnd);
	std::swap(this->mSize, second.mSize);

	return *this;
}

template<typename T>
void List<T>::insert(List<T>::Iterator position, const T& value)
{
	assert(position.mOwner == this);

	if (mSize == 0)
		insert_first(value);
	else if (position.mNode == mBegin.get())
		insert_begin(value);
	else if (position.mNode == nullptr)
		insert_end(value);
	else
		insert_before_position(value, position.mNode);
}

template<typename T>
void List<T>::push_front(const T& value)
{
	if (mSize == 0)
		insert_first(value);
	else
		insert_begin(value);
}

template<typename T>
void List<T>::push_back(const T& value)
{
	if (mSize == 0)
		insert_first(value);
	else
		insert_end(value);
}

template<typename T>
void List<T>::erase(List<T>::Iterator position)
{
	assert(position.mOwner == this);

	if (mSize == 1)
		erase_last();
	else if (position.mNode == mBegin.get())
		erase_begin();
	else if (position.mNode == mEnd)
		erase_end();
	else
		erase_at_position(position.mNode);
}

template<typename T>
void List<T>::pop_front()
{
	if (mSize == 1)
		erase_last();
	else
		erase_begin();
}

template<typename T>
void List<T>::pop_back()
{
	if (mSize == 1)
		erase_last();
	else
		erase_end();
}

template<typename T>
void List<T>::clear()
{
	while (!empty())
		pop_front();
}

template<typename T>
typename List<T>::Iterator List<T>::begin()
{
	return List<T>::Iterator(this, mBegin.get());
}

template<typename T>
typename List<T>::ConstIterator List<T>::begin() const
{
	return cbegin();
}

template<typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{
	return List<T>::ConstIterator(this, mBegin.get());
}

template<typename T>
typename List<T>::Iterator List<T>::end()
{
	return List<T>::Iterator(this, nullptr);
}

template<typename T>
typename List<T>::ConstIterator List<T>::end() const
{
	return cend();
}

template<typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
	return List<T>::ConstIterator(this, nullptr);
}

template<typename T>
std::size_t List<T>::size() const
{
	return mSize;
}

template<typename T>
bool List<T>::empty() const
{
	return mSize == 0;
}

template<typename T>
T& List<T>::front()
{
	assert(mSize > 0);

	return mBegin->data;
}

template<typename T>
const T& List<T>::front() const
{
	assert(mSize > 0);

	return mBegin->data;
}

template<typename T>
T& List<T>::back()
{
	assert(mSize > 0);

	return mEnd->data;
}

template<typename T>
const T& List<T>::back() const
{
	assert(mSize > 0);

	return mEnd->data;
}

template<typename T>
void List<T>::insert_first(const T& value)
{
	assert(mSize == 0);

	mBegin = std::make_unique<List<T>::Node>(value);
	mEnd = mBegin.get();

	mSize++;
}

template<typename T>
void List<T>::insert_begin(const T& value)
{
	assert(mSize > 0);
	assert(mBegin != nullptr);

	auto node = std::make_unique<List<T>::Node>(value);

	node->next = std::move(mBegin);
	node->next->prev = node.get();
	mBegin = std::move(node);

	mSize++;
}

template<typename T>
void List<T>::insert_end(const T& value)
{
	assert(mSize > 0);
	assert(mEnd != nullptr);

	mEnd->next = std::make_unique<List<T>::Node>(value);
	mEnd->next->prev = mEnd;
	mEnd = mEnd->next.get();

	mSize++;
}

template<typename T>
void List<T>::insert_before_position(const T& value, List<T>::Node* position)
{
	assert(mSize >= 2);
	assert(position != nullptr);
	assert(position->prev != nullptr);

	auto node = std::make_unique<List<T>::Node>(value);

	node->next = std::move(position->prev->next);
	node->prev = position->prev;
	node->next->prev = node.get();
	node->prev->next = std::move(node);

	mSize++;
}

template<typename T>
void List<T>::erase_last()
{
	mBegin = nullptr;
	mEnd = nullptr;

	mSize--;
}

template<typename T>
void List<T>::erase_begin()
{
	assert(mSize > 1);
	assert(mBegin != nullptr);

	mBegin = std::move(mBegin->next);
	mBegin->prev = nullptr;

	mSize--;
}

template<typename T>
void List<T>::erase_end()
{
	assert(mSize > 0);
	assert(mEnd != nullptr);

	mEnd = mEnd->prev;
	mEnd->next = nullptr;

	mSize--;
}

template<typename T>
void List<T>::erase_at_position(List<T>::Node* node)
{
	assert(mSize > 2);
	assert(position != nullptr);
	assert(position != mBegin);
	assert(position != mEnd);

	node->next->prev = node->prev;
	node->prev->next = std::move(node->next);

	delete node;

	mSize--;
}