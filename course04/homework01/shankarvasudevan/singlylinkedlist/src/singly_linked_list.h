#pragma once
#include "singly_linked_list_node.h"

class SinglyLinkedList
{
public:
    bool empty();
    SinglyLinkedList() : mFirst(nullptr) {};
    void push_front(const std::size_t value);
    void pop_front();
    SinglyLinkedListNode* front();

private:
    std::unique_ptr<SinglyLinkedListNode> mFirst;
};