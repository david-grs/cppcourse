#include<iostream>
#include "singly_linked_list.h"
#include "counter.h"

int main()
{
    SinglyLinkedList<Counter> list;
    std::cout << "*** USING PUSH FRONT ***" << std::endl;
    Counter node{42};
    list.push_front(node);
    std::cout << Counter::sCtors << " ctors" << std::endl;
    std::cout << Counter::sCopyCtors << " copy ctors" << std::endl;
    std::cout << Counter::sMoveCtors << " move ctors" << std::endl;
    
    Counter::reset_constructor_count();
    std::cout << "*** USING EMPLACE FRONT ***" << std::endl;
    list.emplace_front(42);
    std::cout << Counter::sCtors << " ctors" << std::endl;
    std::cout << Counter::sCopyCtors << " copy ctors" << std::endl;
    std::cout << Counter::sMoveCtors << " move ctors" << std::endl;

    return 0;
}