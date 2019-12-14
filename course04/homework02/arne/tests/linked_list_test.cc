#include "gtest/gtest.h"
#include "linked_list.h"

struct linked_list_tests : public ::testing::Test
{
    LinkedList<int> linkedListInt;
    LinkedList<char> linkedListChar;

    void ExpectEmptyListInt()
    {
        EXPECT_TRUE(&linkedListInt);
        EXPECT_TRUE(linkedListInt.IsEmpty());
        EXPECT_EQ(nullptr, linkedListInt.mNode);
    }

    void ExpectEmptyListChar()
    {
        EXPECT_TRUE(&linkedListChar);
        EXPECT_TRUE(linkedListChar.IsEmpty());
        EXPECT_EQ(nullptr, linkedListChar.mNode);
    }
};

TEST_F(linked_list_tests, default_ctor)
{
    ExpectEmptyListInt();
    ExpectEmptyListChar();
}

TEST_F(linked_list_tests, append_single_to_list_int)
{
    linkedListInt.Append(1);
    EXPECT_FALSE(linkedListInt.IsEmpty());
    EXPECT_EQ(1, linkedListInt.mNode->mData);
}

TEST_F(linked_list_tests, append_single_to_list_char)
{
    linkedListChar.Append('1');
    EXPECT_FALSE(linkedListChar.IsEmpty());
    EXPECT_EQ('1', linkedListChar.mNode->mData);
}

TEST_F(linked_list_tests, append_multiple_to_list_int)
{
    linkedListInt.Append(1);
    linkedListInt.Append(7);
    EXPECT_FALSE(linkedListInt.IsEmpty());
    EXPECT_EQ(1, linkedListInt.mNode->mData);
    EXPECT_EQ(7, linkedListInt.mNode->mNextNode->mData);
}

TEST_F(linked_list_tests, append_multiple_to_list_char)
{
    linkedListChar.Append('1');
    linkedListChar.Append('7');
    EXPECT_FALSE(linkedListChar.IsEmpty());
    EXPECT_EQ('1', linkedListChar.mNode->mData);
    EXPECT_EQ('7', linkedListChar.mNode->mNextNode->mData);
}

TEST_F(linked_list_tests, delete_from_list_int)
{
    linkedListInt.Append(1);
    linkedListInt.Append(7);
    linkedListInt.Append(9);
    linkedListInt.Remove(9);
    linkedListInt.Remove(1);
    linkedListInt.Remove(7);

    ExpectEmptyListInt();
}

TEST_F(linked_list_tests, delete_from_list_char)
{
    linkedListChar.Append('1');
    linkedListChar.Append('7');
    linkedListChar.Append('9');
    linkedListChar.Remove('9');
    linkedListChar.Remove('1');
    linkedListChar.Remove('7');

    ExpectEmptyListChar();
}

TEST_F(linked_list_tests, dont_delete_from_list_int)
{
    linkedListInt.Append(1);
    linkedListInt.Remove(7);
    EXPECT_FALSE(linkedListInt.IsEmpty());
    EXPECT_EQ(1, linkedListInt.mNode->mData);
}

TEST_F(linked_list_tests, dont_delete_from_list_char)
{
    linkedListChar.Append('1');
    linkedListChar.Remove('7');
    EXPECT_FALSE(linkedListChar.IsEmpty());
    EXPECT_EQ('1', linkedListChar.mNode->mData);
}

TEST_F(linked_list_tests, iterate_int)
{
    linkedListInt.Append(1);
    linkedListInt.Append(7);
    linkedListInt.Append(9);
    for (auto&& x : linkedListInt)
    {
        EXPECT_TRUE(x);
    }
}

TEST_F(linked_list_tests, iterate_char)
{
    linkedListChar.Append('1');
    linkedListChar.Append('7');
    linkedListChar.Append('9');
    for (auto x : linkedListChar)
    {
        EXPECT_TRUE(x);
    }
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
