#include "tuple.h"

#include <gtest/gtest.h>

TEST(LinkedListTests, Initialization)
{
    CppCourse::Homework2::LinkedList<int> linkedList;
    EXPECT_TRUE(linkedList.isEmpty());
    EXPECT_EQ(linkedList.size(), 0);
}

TEST(LinkedListTests, SimplePush)
{
    CppCourse::Homework2::LinkedList<int> linkedList;
    EXPECT_EQ(linkedList.size(), 0);

    linkedList.push(10);
    EXPECT_EQ(linkedList.get(0), 10);
    EXPECT_EQ(linkedList.size(), 1);
}

TEST(LinkedListTests, Push)
{
    CppCourse::Homework2::LinkedList<int> linkedList;
    EXPECT_EQ(linkedList.size(), 0);

    for (int i = 0; i < 100; i++)
    {
        linkedList.push(i);
    }
    EXPECT_EQ(linkedList.size(), 100);
}

TEST(LinkedListTests, PushAndRetrieve)
{
    CppCourse::Homework2::LinkedList<int> linkedList;
    EXPECT_EQ(linkedList.size(), 0);

    for (int i = 0; i < 100; i++)
    {
        linkedList.push(i);
    }
    EXPECT_EQ(linkedList.size(), 100);

    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(linkedList.get(i), i);
    }
    EXPECT_EQ(linkedList.size(), 100);
}

TEST(LinkedListTests, SimplePop)
{
    CppCourse::Homework2::LinkedList<int> linkedList;
    EXPECT_EQ(linkedList.size(), 0);

    linkedList.push(10);
    EXPECT_EQ(linkedList.size(), 1);

    int value = linkedList.pop();
    EXPECT_EQ(value, 10);
    EXPECT_EQ(linkedList.size(), 0);
}

TEST(LinkedListTests, PushAndPop)
{
    CppCourse::Homework2::LinkedList<int> linkedList;
    EXPECT_EQ(linkedList.size(), 0);

    for (int i = 0; i < 100; i++)
    {
        linkedList.push(i);
    }
    EXPECT_EQ(linkedList.size(), 100);

    for (int i = 99; i >= 0; i--)
    {
        int value = linkedList.pop();
        EXPECT_EQ(value, i);
    }
    EXPECT_EQ(linkedList.size(), 0);
}

TEST(LinkedListTests, TestIndexOutOfBounds)
{
    CppCourse::Homework2::LinkedList<int> linkedList;
    EXPECT_TRUE(linkedList.isEmpty());
    EXPECT_EQ(linkedList.size(), 0);

    for (int i = 0; i < 100; i++)
    {
        linkedList.push(i);
    }
    EXPECT_EQ(linkedList.size(), 100);

    EXPECT_ANY_THROW(linkedList.get(101));
}

TEST(LinkedListTests, TestEmptyPop)
{
    CppCourse::Homework2::LinkedList<int> linkedList;
    EXPECT_TRUE(linkedList.isEmpty());
    EXPECT_EQ(linkedList.size(), 0);

    EXPECT_ANY_THROW(linkedList.pop());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
