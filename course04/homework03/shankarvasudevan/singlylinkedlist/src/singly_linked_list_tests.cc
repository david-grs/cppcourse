#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include "test_helper.cc"
#include "foo.h"

TEST(SinglyLinkedListTests_Front, ListShouldInitiallyBeEmpty) 
{ 
    SinglyLinkedList<std::size_t> list;
    ASSERT_TRUE(list.empty());
}

TEST(SinglyLinkedListTests_PushFront, SingleElementShouldBeAtFront)
{
    SinglyLinkedList<std::string> list;
    list.push_front("hello");
    ASSERT_FALSE(list.empty());
    ASSERT_EQ("hello", list.front()->get_value());
}

TEST(SinglyLinkedListTests_PushFront, MultipleElementListShouldBeInReverseOrder)
{
    SinglyLinkedList<std::size_t> list;
    std::vector<std::size_t> elements {10, 20, 30};
    TestHelper::PushElementsToFront(&list, elements);
    std::vector<std::size_t> expected {30, 20, 10};
    std::vector<std::size_t> actual = TestHelper::ConvertToVector(&list);
    ASSERT_EQ(expected, actual);
}

TEST(SinglyLinkedListTests_PopFront, ShouldThrowExceptionOnPoppingEmptyList)
{
    SinglyLinkedList<std::size_t> list;
    ASSERT_THROW(list.pop_front(), std::out_of_range);
}

TEST(SinglyLinkedListTests_PopFront, PushingAndPoppingSingleElementShouldResultInEmptyList)
{
    SinglyLinkedList<std::size_t> list;
    list.push_front(42);
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(SinglyLinkedListTests_PopFront, PushAndPopElementsShouldResultInCorrectFinalList)
{
    SinglyLinkedList<std::size_t> list;
    std::vector<std::size_t> elements {10, 20, 10, 30};
    TestHelper::PushElementsToFront(&list, elements);
    list.pop_front();
    list.pop_front();
    std::vector<std::size_t> expected {20, 10};
    std::vector<std::size_t> actual = TestHelper::ConvertToVector(&list);
    ASSERT_EQ(expected, actual);
}

TEST(SinglyLinkedListTests_PushFront, CallsCopyConstructorWhenPassingParameters)
{
    SinglyLinkedList<Foo> list; 
    Foo node{42};
    Foo::reset_copy_constructor_count();
    list.push_front(node);
    ASSERT_EQ(3, Foo::copy_constructor_count);
}

/*TEST(SinglyLinkedListTests_EmplaceFront, DoesNotCallCopyConstructorWhenPassingParameters)
{
    SinglyLinkedList<Foo> list; 
    list.emplace_front(42);
    ASSERT_EQ(3, Foo::num_times_constructed);
}*/