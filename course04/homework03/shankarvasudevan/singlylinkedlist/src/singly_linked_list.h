#pragma once
#include "singly_linked_list_node.h"

template<typename T>
class SinglyLinkedList
{
public:
    SinglyLinkedList() : mFirst{nullptr} {}

    bool empty()
    {
        return mFirst == nullptr;
    }

    void push_front(const T value)
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

    template<typename ...Args>
    void emplace_front(Args&&... args)
    {
        auto node{std::make_unique<SinglyLinkedListNode<T>>(std::forward<Args>(args)...)};
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

    void pop_front()
    {
        if (empty())
        {
            throw std::out_of_range("Cannot pop on empty list");
        }

        mFirst = std::move(mFirst->next);
    }

    SinglyLinkedListNode<T>* front()
    {
        return mFirst.get();
    }

private:
    std::unique_ptr<SinglyLinkedListNode<T>> mFirst;
};