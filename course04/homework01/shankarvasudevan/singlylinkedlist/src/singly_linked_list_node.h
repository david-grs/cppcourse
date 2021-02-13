#pragma once
#include <memory>

class SinglyLinkedListNode
{
public:
    SinglyLinkedListNode(const std::size_t value) : mValue{value} {};
    const std::size_t get_value() { return mValue; }

    std::unique_ptr<SinglyLinkedListNode> next;
private:
    std::size_t mValue;
};