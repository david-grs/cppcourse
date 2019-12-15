#pragma once
#include "singly_linked_list_node.h"

template<class T>
class SinglyLinkedList
{
public:
    bool empty();
    SinglyLinkedList() : mFirst{nullptr} {}
    void push_front(const T value);
    void pop_front();
    SinglyLinkedListNode<T>* front();

private:
    std::unique_ptr<SinglyLinkedListNode<T>> mFirst;
};
