#include "singly_linked_list_node.h"

class SinglyLinkedList
{
public:
    SinglyLinkedList() : mFirst(nullptr) {};
    void push_front(const std::size_t value);
    SinglyLinkedListNode* front();

private:
    std::unique_ptr<SinglyLinkedListNode> mFirst;
};