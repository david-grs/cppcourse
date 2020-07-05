#include "linkedlist.cpp"
#include "gtest/gtest.h"

class TestNode : public ::testing::Test {
public:
    TestNode()
        : mNode{ 0 }
    {
    }
    // Could not figure out how to get gtest to paramaterize over types
    Node<int> mNode;

    void EXPECT_ADDED_NODE_HAS_DATA(int val)
    {
        auto& new_node = mNode.Append(val);
        EXPECT_EQ(new_node.GetData(), val);
        EXPECT_EQ(new_node.Next(), boost::none);
    }

    void AppendMany(std::vector<int> items)
    {
        for (auto i : items) {
            EXPECT_ADDED_NODE_HAS_DATA(i);
        }
    }
};

TEST_F(TestNode, TestConstruct)
{
    ASSERT_EQ(mNode.GetData(), 0);
    ASSERT_EQ(mNode.Next(), boost::none);
}

TEST_F(TestNode, TestAppend)
{
    EXPECT_ADDED_NODE_HAS_DATA(1);
    ASSERT_NE(mNode.Next(), boost::none);
}

TEST_F(TestNode, TestAppendIndex)
{
    AppendMany({ 2, 3, 4, 5, 6 });
    mNode.Append(1, 0);
    ASSERT_EQ(mNode.Next().get().GetData(), 1);
}

TEST_F(TestNode, TestAt)
{
    AppendMany({ 1, 2, 3, 4, 5 });
    ASSERT_EQ(mNode.At(0).get().GetData(), 0);
    ASSERT_EQ(mNode.At(1).get().GetData(), 1);
    ASSERT_EQ(mNode.At(2).get().GetData(), 2);
    ASSERT_EQ(mNode.At(3).get().GetData(), 3);
    ASSERT_EQ(mNode.At(4).get().GetData(), 4);
    ASSERT_EQ(mNode.At(5).get().GetData(), 5);
}

TEST_F(TestNode, TestPop)
{
    AppendMany({ 1, 2, 3, 4, 5 });
    ASSERT_EQ(mNode.Pop().GetData(), 5);
    ASSERT_EQ(mNode.Pop().GetData(), 4);
    ASSERT_EQ(mNode.Pop().GetData(), 3);
    ASSERT_EQ(mNode.Pop().GetData(), 2);
    ASSERT_EQ(mNode.Pop().GetData(), 1);
    ASSERT_EQ(mNode.Pop().GetData(), 0);
}
