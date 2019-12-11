#pragma once

#include <memory>

template <class T>
struct ListNode
{
    T mItem;
    std::shared_ptr<ListNode> mNext;
};

template <class T>
class SingleLinkedList
{

private:
    size_t mSize{0};
    std::unique_ptr<ListNode<T>> mFront{nullptr};

public:
    SingleLinkedList(){}

    explicit SingleLinkedList(std::vector<T> v)
    {
        for (int item:v)
            push_front(item);
    }

    SingleLinkedList(size_t size, T defaultValue)
    {
        for (size_t i = 0; i < size; i++)
            push_front(defaultValue);
    }

    int size(){ return mSize; }

    void push_front(T item)
    {
        std::unique_ptr<ListNode<T>> temporary = std::move(mFront);
        mFront = std::make_unique<ListNode<T>>();
        mFront->mNext = std::move(temporary);
        mFront->mItem = item;
        ++mSize;
    }

    void pop_front()
    {
        if (mSize <= 0)
            throw std::out_of_range("...");

        mFront = std::move(mFront->mNext);
    }

    T front()
    {
        return mFront->mItem;
    }
};
