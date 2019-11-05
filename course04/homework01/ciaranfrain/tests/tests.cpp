#include "tests.h"

void LinkedListShould::AssertSize(const std::size_t size) const
{
	ASSERT_TRUE(mList.size() == size);
	ASSERT_EQ(mList.empty(), size == 0);
}

void LinkedListShould::AssertListContent(const std::vector<int> values) const
{
	AssertSize(values.size());
	for (std::size_t i=0; i<values.size();i++)
	{
		ASSERT_EQ(mList.at(i), values.at(i));
	}
}

// Initial state
TEST_F(LinkedListShould, InitialiseEmpty)
{
	AssertSize(0);
}

TEST_F(LinkedListShould, ThrowIfFrontAccessedWhileEmpty)
{
	EXPECT_THROW(mList.front(), std::out_of_range);
}

TEST_F(LinkedListShould, ThrowIfBackAccessedWhileEmpty)
{
	EXPECT_THROW(mList.front(), std::out_of_range);
}

TEST_F(LinkedListShould, ThrowIfAccessedWhileEmpty)
{
	EXPECT_THROW(mList.at(0), std::out_of_range);
}

// Push Back
TEST_F(LinkedListShould, GrowAfterPushBack)
{
	mList.push_back(1);
	AssertSize(1);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOnePushedBackElementWithAt)
{
	mList.push_back(5);
	ASSERT_EQ(mList.at(0), 5);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOnePushedBackElementWithFront)
{
	mList.push_back(5);
	ASSERT_EQ(mList.front(), 5);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOnePushedBackElementWithBack)
{
	mList.push_back(5);
	ASSERT_EQ(mList.back(), 5);
}

TEST_F(LinkedListShould, InsertPushedBackValueAtBack)
{
	mList.push_back(5);
	mList.push_front(55);
	AssertListContent({55,5});
}

// Push Front
TEST_F(LinkedListShould, GrowAfterPushFront)
{
	mList.push_front(1);
	AssertSize(1);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOnePushedFrontElementWithAt)
{
	mList.push_front(5);
	ASSERT_EQ(mList.at(0), 5);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOnePushedFrontElementWithFront)
{
	mList.push_front(5);
	ASSERT_EQ(mList.front(), 5);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOnePushedFrontElementWithBack)
{
	mList.push_front(5);
	ASSERT_EQ(mList.back(), 5);
}

TEST_F(LinkedListShould, InsertPushedFrontValueAtFront)
{
	mList.push_back(5);
	mList.push_front(55);
	AssertListContent({55,5});
}

// Insert
TEST_F(LinkedListShould, GrowAfterInsert)
{
	mList.insert(1, 0);
	AssertSize(1);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOneInsertedElementWithAt)
{
	mList.insert(5, 0);
	ASSERT_EQ(mList.at(0), 5);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOneInsertedElementWithFront)
{
	mList.push_front(5);
	ASSERT_EQ(mList.front(), 5);
}

TEST_F(LinkedListShould, ReturnCorrectValueOfOneInsertedElementWithBack)
{
	mList.push_front(5);
	ASSERT_EQ(mList.back(), 5);
}

TEST_F(LinkedListShould, InsertValueAtCorrectLocation)
{
	mList.push_back(5);
	mList.push_back(555);
	mList.insert(55, 1);
	AssertListContent({5,55,555});
}

// Erase
TEST_F(LinkedListShould, ThrowIfEraseingInvalidIndex)
{
	EXPECT_THROW(mList.erase(0), std::out_of_range);
}

TEST_F(LinkedListShould, EraseValueAtCorrectLocation)
{
	mList.push_back(5);
	mList.push_back(55);
	mList.push_back(555);
	mList.erase(1);
	AssertListContent({5,555});
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
