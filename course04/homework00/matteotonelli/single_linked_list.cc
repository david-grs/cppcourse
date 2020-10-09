#include "single_linked_list.h"

SingleLinkedList::SingleLinkedList(size_t size, int defaultValue)
{
    for (size_t i = 0; i < size; i++)
        push_front(defaultValue);
}

SingleLinkedList::SingleLinkedList(std::vector<int> v)
{
    for (int item:v)
        push_front(item);
}

void SingleLinkedList::push_front(int item)
{
    std::shared_ptr<ListNode> temporary = mFront;
    mFront = std::make_shared<ListNode>();
    mFront->mNext = temporary;
    mFront->mItem = item;
    ++mSize;
}

void SingleLinkedList::pop_front()
{
    if (mSize == 0)
        return;

    mFront = mFront->mNext;
    --mSize;
}

int SingleLinkedList::front()
{
    if (mSize == 0)
        throw std::out_of_range("...");

    return mFront->mItem;
}
