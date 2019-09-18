#include "tuple.h"

#include <gtest/gtest.h>

template <class... Args> using Tuple = CppCourse::TupleHomework::Tuple<Args...>;

TEST(LinkedListTests, Initialization)
{
    Tuple<int, int, int> t = Tuple<int, int, int>(1, 2, 3);

    EXPECT_EQ(t.Size(), 3);
    EXPECT_EQ(t.Get(0), 1);
    EXPECT_EQ(t.Get(1), 2);
    EXPECT_EQ(t.Get(2), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
