#include "gtest/gtest.h"
#include "linked_list.h"

struct linked_list_tests : public ::testing::Test
{
    LinkedList* linkedList = new LinkedList();

    ~linked_list_tests() { delete linkedList; }

    void ExpectEmptyList()
    {
        EXPECT_TRUE(&linkedList);
        EXPECT_TRUE(linkedList->IsEmpty());
        EXPECT_EQ(nullptr, linkedList->mFirstNode);
        EXPECT_EQ(nullptr, linkedList->mLastNode);
    }
};


TEST_F(linked_list_tests, default_ctor)
{
    ExpectEmptyList();
}

TEST_F(linked_list_tests, append_single_to_list)
{
    linkedList->Append(1);
    EXPECT_FALSE(linkedList->IsEmpty());
    EXPECT_EQ(linkedList->mFirstNode, linkedList->mLastNode);
    EXPECT_EQ(1, linkedList->mFirstNode->mData);
}

TEST_F(linked_list_tests, append_multiple_to_list)
{
    linkedList->Append(1);
    linkedList->Append(7);
    EXPECT_FALSE(linkedList->IsEmpty());
    EXPECT_NE(linkedList->mFirstNode, linkedList->mLastNode);
    EXPECT_EQ(1, linkedList->mFirstNode->mData);
    EXPECT_EQ(7, linkedList->mLastNode->mData);
}

TEST_F(linked_list_tests, delete_from_list)
{
    linkedList->Append(1);
    linkedList->Append(7);
    linkedList->Append(9);
    linkedList->~LinkedList();
    ExpectEmptyList();
}

TEST_F(linked_list_tests, dont_delete_from_list)
{
    linkedList->Append(1);
    linkedList->Remove(7);
    EXPECT_FALSE(linkedList->IsEmpty());
    EXPECT_EQ(linkedList->mFirstNode, linkedList->mLastNode);
    EXPECT_EQ(1, linkedList->mLastNode->mData);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
