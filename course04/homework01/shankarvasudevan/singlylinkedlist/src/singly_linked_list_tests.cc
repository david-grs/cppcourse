#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include "test_helper.cc"

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
    std::vector<size_t> elements {10, 20, 30};
    TestHelper::PushElementsToFront(&list, elements);
    std::vector<size_t> expected {30, 20, 10};
    std::vector<size_t> actual = TestHelper::ConvertToVector(&list);
    ASSERT_EQ(expected, actual);
}

