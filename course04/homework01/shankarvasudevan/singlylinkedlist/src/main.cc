#include <iostream>
#include "singly_linked_list.h"

int main()
{
    bool passed{false};
    std::cout << "Testing singly linked list ..." << std::endl;

    std::cout << "Test 1: Empty List" << std::endl;
    SinglyLinkedList list1;
    passed = (list1.front() == nullptr);
    std::cout << "Result = " << passed << std::endl;

    passed = false;
    std::cout << "Test 2: Add single element" << std::endl;
    SinglyLinkedList list2;
    list2.push_front(42);
    SinglyLinkedListNode* first = list2.front();
    size_t value = first->get_value();
    passed = (value == 42) && (first->next == nullptr);
    std::cout << "Result = " << passed << std::endl;

    passed = false;
    std::cout << "Test 3: Add multiple elements" << std::endl;
    SinglyLinkedList list3;
    list3.push_front(25);
    list3.push_front(50);
    list3.push_front(75);

    SinglyLinkedListNode* firstNode = list3.front();
    SinglyLinkedListNode* secondNode = firstNode->next.get();
    SinglyLinkedListNode* thirdNode = secondNode->next.get();

    passed = (firstNode->get_value() == 75) 
        && (secondNode->get_value() == 50) 
        && (thirdNode->get_value() == 25)
        && (thirdNode->next == nullptr);

    std::cout << "Result = " << passed << std::endl;

    return 0;
}