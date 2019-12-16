#include<iostream>
#include "singly_linked_list.cc"
#include "test_helper.cc" 
#include <vector> 

struct A
{
    public:
        A(std::size_t fooValue, std::size_t barValue) : mFoo(fooValue), mBar(barValue) 
        {
            ++num_times_constructed;
        };

        std::size_t num_times_constructed = 0;
        std::size_t mFoo;
        std::size_t mBar;
};

int main()
{
    SinglyLinkedList<A> list;
    std::vector<A> elements 
    {
        A(1, 2), 
        A(3, 4), 
        A(5, 6)
    };

    TestHelper::PushElementsToFront(&list, elements);
    list.emplace_back(7, 8);

    std::vector<A> actual = TestHelper::ConvertToVector(&list);

    for (auto a : actual)
    {
        std::cout << "[foo: " << a.mFoo << ", bar: " << a.mBar << "]" << std::endl;
    }

    return 0;
}