#include "list.h"
#include "gtest/gtest.h"

TEST(LinkedList, init) { LinkedList list; }

TEST(LinkedList, length) {
  LinkedList list;
  EXPECT_EQ(list.len(), 0);

  Foo foo{5};
  Foo foo2{6};

  list.push_back(foo);
  EXPECT_EQ(list.len(), 1);
  list.push_back(foo2);
  EXPECT_EQ(list.len(), 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
