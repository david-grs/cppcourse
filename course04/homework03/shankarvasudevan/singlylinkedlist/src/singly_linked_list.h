#pragma once
#include "singly_linked_list_node.h"

template<typename T>
class SinglyLinkedList
{
public:
    bool empty();
    SinglyLinkedList() : mFirst{nullptr} {}
    void push_front(const T value);

    template<typename ...Args>
    void emplace_back(Args&&... args);

    void pop_front();
    SinglyLinkedListNode<T>* front();

private:
    std::unique_ptr<SinglyLinkedListNode<T>> mFirst;
};
