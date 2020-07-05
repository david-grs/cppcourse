#include "gtest/gtest.h"
#include "linkedlist.cpp"

class TestNode : public::testing::Test {
public:
    TestNode() : mNode{0} {}
    // Could not figure out how to get gtest to paramaterize over types
    Node<int> mNode;

    void EXPECT_ADDED_NODE_HAS_DATA(int val) {
        auto &new_node = mNode.Append(val);
        EXPECT_EQ(new_node.GetData(), val);
        EXPECT_EQ(new_node.Next(), boost::none);
    }

    void AppendMany(std::vector<int> items) {
        for (auto i : items) {
            mNode.Append(i);
        }
    }
};

TEST_F (TestNode, TestConstruct) {
    ASSERT_EQ(mNode.GetData(), 0);
    ASSERT_EQ(mNode.Next(), boost::none);
}

TEST_F (TestNode, TestAppend) {
    EXPECT_ADDED_NODE_HAS_DATA(1);
    ASSERT_NE(mNode.Next(), boost::none);
}

TEST_F (TestNode, TestAppendIndex) {
    AppendMany({2, 3, 4, 5, 6});
    mNode.Append(1, 0);
    ASSERT_EQ(mNode.Next().get().GetData(), 1);
}

