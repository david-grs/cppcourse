#include<iostream>
#include "singly_linked_list.h"

struct A
{
    public:
        static std::size_t copy_constructor_count;
        A(const A& other) : mValue(0)
        {
            ++copy_constructor_count;
        }

        A(std::size_t value) : mValue(value) {}        
        
        static void reset_constructor_count()
        {
            copy_constructor_count = 0;
        }
        
        std::size_t get_foo() { return mValue; }

    private:
        std::size_t mValue;   
};

std::size_t A::copy_constructor_count = 0;

int main()
{
    SinglyLinkedList<A> list;
    std::cout << "*** USING PUSH FRONT ***" << std::endl;
    A node{42};
    list.push_front(node);
    std::cout << "Copy constructor count = " << A::copy_constructor_count << std::endl;
    
    A::reset_constructor_count();
    std::cout << "*** USING EMPLACE FRONT ***" << std::endl;
    list.emplace_front(42);
    std::cout << "Copy constructor count = " << A::copy_constructor_count << std::endl;

    return 0;
}