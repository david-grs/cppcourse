#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include "test_helper.cc"

TEST(SinglyLinkedListTests_Front, ListShouldInitiallyBeEmpty) 
{ 
    SinglyLinkedList list;
    ASSERT_TRUE(list.empty());
}

TEST(SinglyLinkedListTests_PushFront, SingleElementShouldBeAtFront)
{
    SinglyLinkedList list;
    list.push_front(42);
    ASSERT_FALSE(list.empty());
    ASSERT_EQ(42, list.front()->get_value());
}

TEST(SinglyLinkedListTests_PushFront, MultipleElementListShouldBeInReverseOrder)
{
    SinglyLinkedList list;
    std::vector<size_t> elements {10, 20, 30};
    TestHelper::PushElementsToFront(&list, elements);
    std::vector<size_t> expected {30, 20, 10};
    std::vector<size_t> actual = TestHelper::ConvertToVector(&list);
    ASSERT_EQ(expected, actual);
}

TEST(SinglyLinkedListTests_PopFront, ShouldThrowExceptionOnPoppingEmptyList)
{
    SinglyLinkedList list;
    ASSERT_THROW(list.pop_front(), std::out_of_range);
}

TEST(SinglyLinkedListTests_PopFront, PushingAndPoppingSingleElementShouldResultInEmptyList)
{
    SinglyLinkedList list;
    list.push_front(42);
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(SinglyLinkedListTests_PopFront, PushAndPopElementsShouldResultInCorrectFinalList)
{
    SinglyLinkedList list;
    std::vector<size_t> elements {10, 20, 10, 30};
    TestHelper::PushElementsToFront(&list, elements);
    list.pop_front();
    list.pop_front();
    std::vector<size_t> expected {20, 10};
    std::vector<size_t> actual = TestHelper::ConvertToVector(&list);
    ASSERT_EQ(expected, actual);
}

