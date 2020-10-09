#pragma once

#include <memory>
#include <vector>

struct ListNode
{
    int mItem;
    std::shared_ptr<ListNode> mNext;
};

class SingleLinkedList
{

private:
    size_t mSize{0};
    std::shared_ptr<ListNode> mFront{nullptr};

public:
    SingleLinkedList(){}
    explicit SingleLinkedList(std::vector<int> v);
    SingleLinkedList(size_t size, int defaultValue);

    int size(){ return mSize; }

    void push_front(int item);
    void pop_front();
    int front();
};
