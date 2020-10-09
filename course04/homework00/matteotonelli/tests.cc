#include <gtest/gtest.h>
#include <vector>
#include "ordered_array.h"
#include "single_linked_list.h"

class OrderedArrayTest : public ::testing::Test {
protected:

    void testSize(const std::vector<int>& v, size_t n)
    {
        OrderedArray oA{v};
        ASSERT_EQ(oA.size(),n);
    }

    void testOrder(const std::vector<int>& v)
    {
        OrderedArray oA{v};
        for(size_t i = 0; i < v.size()-1; ++i)
        {
            ASSERT_TRUE(oA[i]<=oA[i+1]);
        }
    }

};

class SingleLinkedListTest : public ::testing::Test {
protected:

    void testVectorConstructor(const std::vector<int>& v, size_t n)
    {
        SingleLinkedList oA{v};
        ASSERT_EQ(oA.size(),n);
    }

    void testSizeConstructor(size_t size, int defaultValue)
    {
        OrderedArray oA{5,0};
        for(size_t i = 0; i < oA.size()-1; ++i)
        {
            ASSERT_TRUE(oA[i]<=oA[i+1]);
        }
    }

};

class UniquePtrTest : public ::testing::Test
{
protected:
    void testUniquePtrConstructor(int number);

};

TEST_F(OrderedArrayTest,testSortedArraySize)
{
    testSize({1,2,3},3);
    testSize({},0);
    testSize({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},20);
}

TEST_F(OrderedArrayTest,testOrder)
{
    testOrder({2,3,4,5});
    testOrder({9,8,3,6});
    testOrder({19,90,89,19,14,54});
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
