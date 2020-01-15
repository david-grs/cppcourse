#include "gtest/gtest.h"
#include "singly_linked_list.h"
#include "test_helper.cc"
#include "counter.h"

class SinglyLinkedListTests : public ::testing::Test 
{
    protected:
        SinglyLinkedListTests() 
        {
            Counter::reset_constructor_count();
        }
};

TEST_F(SinglyLinkedListTests, ListShouldInitiallyBeEmpty) 
{ 
    SinglyLinkedList<std::size_t> list;
    ASSERT_TRUE(list.empty());
}

TEST_F(SinglyLinkedListTests, SingleElementShouldBeAtFront)
{
    SinglyLinkedList<std::string> list;
    list.push_front("hello");
    ASSERT_FALSE(list.empty());
    ASSERT_EQ("hello", list.front()->get_value());
}

TEST_F(SinglyLinkedListTests, MultipleElementListShouldBeInReverseOrder)
{
    SinglyLinkedList<std::size_t> list;
    std::vector<std::size_t> elements {10, 20, 30};
    TestHelper::PushElementsToFront(&list, elements);
    std::vector<std::size_t> expected {30, 20, 10};
    std::vector<std::size_t> actual = TestHelper::ConvertToVector(&list);
    ASSERT_EQ(expected, actual);
}

TEST_F(SinglyLinkedListTests, ShouldThrowExceptionOnPoppingEmptyList)
{
    SinglyLinkedList<std::size_t> list;
    ASSERT_THROW(list.pop_front(), std::out_of_range);
}

TEST_F(SinglyLinkedListTests, PushingAndPoppingSingleElementShouldResultInEmptyList)
{
    SinglyLinkedList<std::size_t> list;
    list.push_front(42);
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST_F(SinglyLinkedListTests, PushAndPopElementsShouldResultInCorrectFinalList)
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

TEST_F(SinglyLinkedListTests, PushFrontCallsCorrectConstructors)
{
    SinglyLinkedList<Counter> list; 
    Counter node{42};
    list.push_front(node);
    ASSERT_EQ(1, Counter::sCtors);
    ASSERT_EQ(2, Counter::sCopyCtors);
    ASSERT_EQ(0, Counter::sMoveCtors);
}

TEST_F(SinglyLinkedListTests, EmplaceFrontCallsCorrectConstructors)
{
    SinglyLinkedList<Counter> list;
    list.emplace_front(42);
    ASSERT_EQ(1, Counter::sCtors);
    ASSERT_EQ(1, Counter::sCopyCtors);
    ASSERT_EQ(0, Counter::sMoveCtors);
}