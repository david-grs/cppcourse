#include "gtest/gtest.h"
#include "llist.cpp"

TEST(NodeTest, ReadingOut)
{
  Node m = {3};
  ASSERT_EQ(3, m.melem);
  Node mcopy = m;
  ASSERT_EQ(3, mcopy.melem);
  Node m2 = {4};
  ASSERT_EQ(4, m2.melem);
  mcopy = m2;
  ASSERT_EQ(4, mcopy.melem);
  Node m3 = Node(m2);
  ASSERT_EQ(4, m3.melem);
}

TEST(LLintTest, Creating)
{
  Node m = {3};
  LLint l1 = m;
  ASSERT_EQ(3, (*l1.mlist).melem);
  LLint l2 = l1;
  ASSERT_EQ(3, (*l2.mlist).melem);
}

TEST(LLintTest, cars)
{
  Node m = {3};
  LLint l1 = m;
  ASSERT_EQ(3, l1.car());
}

TEST(LLintTest, CarOnEmptyThrows)
{
  Node m;
  LLint l = m;
  try
    {
      int i = l.car();
      i += 1;
    }
  catch (std::runtime_error const &err)
    {
      EXPECT_EQ(err.what(), std::string("Car called on empty mlist."));
    }
}
TEST(LLintTest, cdrOnEmpty)
{
  Node m;
  LLint l = m;
  LLint cdrOfL = l.cdr();
  int i = 99;
  if (cdrOfL)
    {
      i = -1;
    }
  else
    {
      i = 42;
    }

  ASSERT_EQ(i, 42);
}
TEST(LLintTest, consReading)
{
  LLint l = cons(1, cons(2, cons(3, cons(4, LLint::emptyList()))));
  ASSERT_EQ(l.car(), 1);
  ASSERT_EQ(l.cdr().car(), 2);
  ASSERT_EQ(l.cdr().cdr().car(), 3);
  ASSERT_EQ(l.cdr().cdr().cdr().car(), 4);
}
TEST(LLintTest, nth)
{
  LLint l = cons(1, cons(2, cons(3, cons(4, LLint::emptyList()))));
  ASSERT_EQ(nth(l, 0), 1);
  ASSERT_EQ(nth(l, 1), 2);
  ASSERT_EQ(nth(l, 2), 3);
  ASSERT_EQ(nth(l, 3), 4);
  try
    {
      int i = nth(l, 4);
      i += 1;
    }
  catch (std::runtime_error const &err)
    {
      EXPECT_EQ(err.what(), std::string("Car called on empty mlist."));
    }
  try
    {
      int i = nth(l, -1);
      i += 1;
    }
  catch (std::runtime_error const &err)
    {
      EXPECT_EQ(err.what(), std::string("Cant index with negative index"));
    }
}

TEST(LLintTest, pushBack)
{
  LLint lshort = cons(1, cons(2, cons(3, cons(4, LLint::emptyList()))));
  LLint l = pushBack(lshort, 42);
  ASSERT_EQ(nth(l, 0), 1);
  ASSERT_EQ(nth(l, 1), 2);
  ASSERT_EQ(nth(l, 2), 3);
  ASSERT_EQ(nth(l, 3), 4);
  ASSERT_EQ(nth(l, 4), 42);
  try
    {
      int i = nth(l, 5);
      i += 1;
    }
  catch (std::runtime_error const &err)
    {
      EXPECT_EQ(err.what(), std::string("Car called on empty mlist."));
    }
  try
    {
      int i = nth(l, -1);
      i += 1;
    }
  catch (std::runtime_error const &err)
    {
      EXPECT_EQ(err.what(), std::string("Cant index with negative index"));
    }
}

TEST(LLintTest, len)
{
  LLint l = cons(1, cons(2, cons(3, cons(4, LLint::emptyList()))));
  ASSERT_EQ(len(l), 4);
  ASSERT_EQ(len(l.cdr()), 3);
  ASSERT_EQ(len(l.cdr().cdr()), 2);
  ASSERT_EQ(len(l.cdr().cdr().cdr()), 1);
  ASSERT_EQ(len(l.cdr().cdr().cdr().cdr()), 0);
}
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
