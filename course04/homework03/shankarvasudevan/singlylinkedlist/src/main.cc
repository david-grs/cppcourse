#include<iostream>
#include "singly_linked_list.h"
#include <vector> 

struct A
{
    public:
        static std::size_t num_times_constructed;

        A(const A&)
        {
            std::cout << "Copy constructor" << std::endl;
            ++num_times_constructed;
        }

        A(std::size_t fooValue, std::size_t barValue) : mFoo(fooValue), mBar(barValue) 
        {
            std::cout << "Regular constructor" << std::endl;
            ++num_times_constructed;
        };

        std::size_t mFoo;
        std::size_t mBar;
};

std::size_t A::num_times_constructed = 0;

int main()
{
    SinglyLinkedList<A> list;
    std::cout << "*** USING PUSH FRONT ***" << std::endl;
    A node{1, 2};
    list.push_front(node);

    std::cout << "*** USING EMPLACE FRONT ***" << std::endl;
    list.emplace_front(3, 4);

    std::cout << "Num times A constructed = " << A::num_times_constructed << std::endl;

    return 0;
}