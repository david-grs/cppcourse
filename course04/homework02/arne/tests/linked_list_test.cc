#include "gtest/gtest.h"
#include "linked_list.h"

struct linked_list_tests : public ::testing::Test
{
    LinkedList linkedList;

    void ExpectEmptyList()
    {
        EXPECT_TRUE(&linkedList);
        EXPECT_TRUE(linkedList.IsEmpty());
        EXPECT_EQ(nullptr, linkedList.mNode);
    }
};


TEST_F(linked_list_tests, default_ctor)
{
    ExpectEmptyList();
}

TEST_F(linked_list_tests, append_single_to_list)
{
    linkedList.Append(1);
    EXPECT_FALSE(linkedList.IsEmpty());
    EXPECT_EQ(1, linkedList.mNode->mData);
}

TEST_F(linked_list_tests, append_multiple_to_list)
{
    linkedList.Append(1);
    linkedList.Append(7);
    EXPECT_FALSE(linkedList.IsEmpty());
    EXPECT_EQ(1, linkedList.mNode->mData);
    EXPECT_EQ(7, linkedList.mNode->mNextNode->mData);
}

TEST_F(linked_list_tests, delete_from_list)
{
    linkedList.Append(1);
    linkedList.Append(7);
    linkedList.Append(9);
    linkedList.Remove(9);
    linkedList.Remove(1);
    linkedList.Remove(7);

    ExpectEmptyList();
}

TEST_F(linked_list_tests, dont_delete_from_list)
{
    linkedList.Append(1);
    linkedList.Remove(7);
    EXPECT_FALSE(linkedList.IsEmpty());
    EXPECT_EQ(1, linkedList.mNode->mData);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
