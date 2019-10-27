#include "gtest/gtest.h"
#include "sorted_array.h"

TEST(SortedArrayTests, EmptyArraySizeShouldBeZero) 
{ 
    SortedArray a(5);
    ASSERT_EQ(0, a.size());
}

TEST(SortedArrayTests, SingleElementArray)
{
    SortedArray a(5);
    a.push_back(7);
    ASSERT_EQ(1, a.size());
    EXPECT_EQ(7, a[0]);
    EXPECT_EQ(7, a.at(0));
}

TEST(SortedArrayTests, ElementsAddedInOrder)
{
    SortedArray a(5);
    a.push_back(4);
    a.push_back(8);
    a.push_back(12);
    ASSERT_EQ(3, a.size());
    EXPECT_EQ(4, a[0]);
    EXPECT_EQ(4, a.at(0));
    EXPECT_EQ(8, a[1]);
    EXPECT_EQ(8, a.at(1));
    EXPECT_EQ(12, a[2]);
    EXPECT_EQ(12, a.at(2));
}

TEST(SortedArrayTests, ElementsAddedOutOfOrder)
{
    SortedArray a(5);
    a.push_back(8);
    a.push_back(4);
    a.push_back(12);
    ASSERT_EQ(3, a.size());
    EXPECT_EQ(4, a[0]);
    EXPECT_EQ(4, a.at(0));
    EXPECT_EQ(8, a[1]);
    EXPECT_EQ(8, a.at(1));
    EXPECT_EQ(12, a[2]);
    EXPECT_EQ(12, a.at(2));
}

TEST(SortedArrayTests, AtIndexOutOfBoundsShouldThrowException)
{
    SortedArray a(5);
    a.push_back(8);
    a.push_back(4);
    a.push_back(12);
    EXPECT_THROW(a.at(4), std::out_of_range);
}

TEST(SortedArrayTests, ReachedCapacityShouldThrowException)
{
    SortedArray a(0);
    EXPECT_THROW(a.push_back(2), std::out_of_range);
}

