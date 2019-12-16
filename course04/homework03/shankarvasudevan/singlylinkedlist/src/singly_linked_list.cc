#include "singly_linked_list.h"
#include <string>

template<typename T>
bool SinglyLinkedList<T>::empty()
{
    return mFirst == nullptr;
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T value)
{
    auto node{std::make_unique<SinglyLinkedListNode<T>>(value)};
    if (mFirst == nullptr)
    {
        mFirst = std::move(node);
    }
    else
    {
        node->next = std::move(mFirst);
        mFirst = std::move(node);
    }
}

template<typename T>
void SinglyLinkedList<T>::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("Cannot pop on empty list");
    }

    mFirst = std::move(mFirst->next);
}

template<typename T>
SinglyLinkedListNode<T>* SinglyLinkedList<T>::front()
{
    return mFirst.get();
}

template<typename T>
template<typename ...Args>
void SinglyLinkedList<T>::emplace_back(Args&&... args)
{
    // handle the case if curr is nullptr

    // go to the last element
    SinglyLinkedListNode<T>* curr = mFirst.get();
    while (curr->next != nullptr)
    {
        curr = curr->next.get();
    }

    T value(std::forward<Args>(args)...);
    curr->next = std::move(std::make_unique<SinglyLinkedListNode<T>>(value));
}

template bool SinglyLinkedList<std::size_t>::empty();
template SinglyLinkedListNode<std::size_t>* SinglyLinkedList<std::size_t>::front();
template void SinglyLinkedList<std::size_t>::push_front(const std::size_t value);
template void SinglyLinkedList<std::size_t>::pop_front();

template bool SinglyLinkedList<std::string>::empty();
template SinglyLinkedListNode<std::string>* SinglyLinkedList<std::string>::front();
template void SinglyLinkedList<std::string>::push_front(const std::string value);
template void SinglyLinkedList<std::string>::pop_front();
