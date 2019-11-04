#include "singly_linked_list.h"

bool SinglyLinkedList::empty()
{
    return mFirst == nullptr;
}

void SinglyLinkedList::push_front(std::size_t value)
{
    auto node{std::make_unique<SinglyLinkedListNode>(value)};
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

void SinglyLinkedList::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("Cannot pop on empty list");
    }

    mFirst = std::move(mFirst->next);
}

SinglyLinkedListNode* SinglyLinkedList::front()
{
    return mFirst.get();
}
