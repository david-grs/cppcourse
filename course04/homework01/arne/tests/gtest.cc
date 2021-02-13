#include "gtest/gtest.h"
#include "sarray.h"

struct sarray_tests : public ::testing::Test
{
    sarray mySarray;
};

TEST_F(sarray_tests, default_ctor)
{
    EXPECT_TRUE(&mySarray);
    EXPECT_EQ(32, mySarray.MaxSize);
}

TEST_F(sarray_tests, single_push_back)
{
    mySarray.push_back(1);
    EXPECT_EQ(mySarray[0], 1);
}

TEST_F(sarray_tests, sorted_push_back)
{
    mySarray.push_back(1);
    mySarray.push_back(10);
    mySarray.push_back(-50);
    mySarray.push_back(11);
    mySarray.push_back(-110);
    mySarray.push_back(2);
    EXPECT_EQ(mySarray[0], -110);
    EXPECT_EQ(mySarray[1], -50);
    EXPECT_EQ(mySarray[2], 1);
    EXPECT_EQ(mySarray[3], 2);
    EXPECT_EQ(mySarray[4], 10);
    EXPECT_EQ(mySarray[5], 11);
}

TEST_F(sarray_tests, push_back_max_size_exceeded)
{
    EXPECT_THROW(for (int i = 0; i < 34; i++) { mySarray.push_back(1); }, std::runtime_error);
}

TEST_F(sarray_tests, at_out_of_range)
{
    EXPECT_THROW(mySarray.at(33), std::out_of_range);
}

TEST_F(sarray_tests, at_within_range)
{
    mySarray.push_back(1);
    EXPECT_EQ(mySarray.at(0), 1);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
