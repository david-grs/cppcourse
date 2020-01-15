#pragma once
#include <memory>

template<typename T, typename... Args>
struct SinglyLinkedListNode
{
public:
    SinglyLinkedListNode(const T& value) : mValue(value) {};
    SinglyLinkedListNode(Args&&... args) : mValue(std::forward<Args>(args)...) {};

    const T get_value() { return mValue; }

    std::unique_ptr<SinglyLinkedListNode> next;
private:
    T mValue;
};