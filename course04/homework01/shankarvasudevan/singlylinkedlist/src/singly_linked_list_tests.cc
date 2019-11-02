#include "gtest/gtest.h"
#include "singly_linked_list.h"

TEST(SinglyLinkedListTests, ListShouldInitiallyBeEmpty) 
{ 
    SinglyLinkedList list;
    ASSERT_EQ(nullptr, list.front());
}

TEST(SinglyLinkedListTests, SingleElementShould)
{
    SinglyLinkedList list;
    list.push_front(42);
    ASSERT_EQ(42, list.front()->get_value());
    ASSERT_EQ(nullptr, list.front()->next);
}

TEST(SinglyLinkedListTests, MultipleElementListShouldBeInReverseOrder)
{
    SinglyLinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    SinglyLinkedListNode* first = list.front();
    SinglyLinkedListNode* second = first->next.get();
    SinglyLinkedListNode* third = second->next.get();
    ASSERT_EQ(30, first->get_value());
    ASSERT_EQ(20, second->get_value());
    ASSERT_EQ(10, third->get_value());
    ASSERT_EQ(nullptr, third->next);
}

