#include <gtest/gtest.h>
#include "list.h"

struct ListTest : public ::testing::Test
{
	LinkedListInt lli;
};

// Just for convenience
auto& Next = LinkedListInt::Next;

TEST_F(ListTest, Init)
{
	EXPECT_EQ(lli.First(), nullptr);
}

TEST_F(ListTest, EmptyList_Remove)
{
	EXPECT_THROW(lli.RemoveFront(), LinkedListInt::RemoveException);
}

TEST_F(ListTest, InsertFront)
{
	lli.InsertFront(1);
	EXPECT_EQ(lli.First()->Get(), 1);
}

TEST_F(ListTest, InsertTwoFront)
{
	lli.InsertFront(1);
	lli.InsertFront(2);


	const auto& first = lli.First();
	EXPECT_EQ(first->Get(), 2);
	EXPECT_EQ(Next(first)->Get(), 1);
	EXPECT_EQ(Next(Next(first)), nullptr);
}

TEST_F(ListTest, InsertTwoFrontThenRemove)
{
	lli.InsertFront(1);
	lli.InsertFront(2);

	lli.RemoveFront();
	EXPECT_EQ(lli.First()->Get(),  1);

	lli.RemoveFront();
	EXPECT_EQ(lli.First(),  nullptr);
}

TEST_F(ListTest, InsertAfter)
{
	lli.InsertFront(3);
	lli.InsertFront(1);

	lli.InsertAfter(lli.First(), 2);

	EXPECT_EQ(lli.First()->Get(), 1);
	EXPECT_EQ(Next(lli.First())->Get(), 2);
	EXPECT_EQ(Next(Next(lli.First()))->Get(), 3);
}

TEST_F(ListTest, RemoveAfter)
{
	lli.InsertFront(3);
	lli.InsertFront(2);
	lli.InsertFront(1);

	lli.RemoveAfter(lli.First());

	EXPECT_EQ(lli.First()->Get(), 1);
	EXPECT_EQ(Next(lli.First())->Get(), 3);
	EXPECT_EQ(Next(Next(lli.First())), nullptr);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
