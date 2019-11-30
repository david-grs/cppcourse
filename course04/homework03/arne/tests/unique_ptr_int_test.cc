#include "gtest/gtest.h"
#include "unique_ptr_int.h"

struct unique_ptr_int_tests : public ::testing::Test
{
    unique_ptr_int my_unique_ptr_int;
    unique_ptr_int my_unique_ptr_int2 = unique_ptr_int(new int(1));
    int* intPtr = nullptr;
    ~unique_ptr_int_tests() { delete intPtr; }
};

TEST_F(unique_ptr_int_tests, ctor)
{
    EXPECT_TRUE(&my_unique_ptr_int);
    EXPECT_TRUE(my_unique_ptr_int2.Get());
    EXPECT_TRUE(*my_unique_ptr_int2);
    EXPECT_EQ(1, *my_unique_ptr_int2.Get());
    EXPECT_EQ(1, *my_unique_ptr_int2);
}

TEST_F(unique_ptr_int_tests, unique)
{
    my_unique_ptr_int = std::move(my_unique_ptr_int2);
    EXPECT_FALSE(my_unique_ptr_int2.Get());
    EXPECT_TRUE(my_unique_ptr_int.Get());
}

TEST_F(unique_ptr_int_tests, release)
{
    intPtr = my_unique_ptr_int2.Release();
    EXPECT_FALSE(my_unique_ptr_int2.Get());
    EXPECT_EQ(1, *intPtr);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
