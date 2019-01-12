//
// Created by gavin on 19/12/2018.
//
#include "list.h"
#include <cassert>
#include <vector>


std::vector<int> get_elements(List& list)
{
    std::vector<int> elements;
    for(std::size_t i=0; i < list.size(); i++)
    {
        elements.push_back(list.get(i));
    }
    return elements;
}

void test_push()
{
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.push_front(5);
    std::vector<int> test_elements{5, 4, 1, 2, 3};
    assert(get_elements(list) == test_elements);
}

void test_insert()
{
    List list;
    list.insert(0, 3);
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(3, 4);
    std::vector<int> test_elements{1, 2, 3, 4};
    assert(get_elements(list) == test_elements);
}
void test_clear()
{
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    std::vector<int> test_elements{1, 2, 3};
    assert(list.size() == 0);
}

void test_get()
{
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.get(0) == 1);
    assert(list.get(2) == 3);
}

void test_size()
{
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.size() == 3);
    list.pop_back();
    list.pop_back();
    list.pop_back();
    assert(list.size() == 0);
}

void test_erase()
{
    List list{1,2,3};
    list.erase(1);
    assert(list.get(1) == 3);
}

void test_copy()
{
    List list{1,2,3};
    List list2(list);
    assert(get_elements(list) == get_elements(list2));
}

int main()
{
    test_clear();
    test_push();
    test_insert();
    test_get();
    test_size();
    test_erase();
    test_copy();
}