#include "singly_linked_list.h"

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

SinglyLinkedListNode* SinglyLinkedList::front()
{
    return mFirst.get();
}
