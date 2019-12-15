#pragma once
#include <memory>

template<class T>
class SinglyLinkedListNode
{
public:
    SinglyLinkedListNode(const T value) : mValue{value} {}
    const T get_value() { return mValue; }

    std::unique_ptr<SinglyLinkedListNode> next;
private:
    T mValue;
};