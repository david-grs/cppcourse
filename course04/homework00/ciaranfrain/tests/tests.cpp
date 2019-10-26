#include "tests.h"

#include <algorithm>

const int SortedArrayShould::mDefaultMaxSize = 5;

SortedArrayShould::SortedArrayShould(): mSortedArray(mDefaultMaxSize)
{}

void SortedArrayShould::InsertValues(const std::vector<int>& values)
{
	for (const auto& n : values)
	{
		mSortedArray.Insert(n);
	}
}

TEST_F(SortedArrayShould, InitialiseEmpty)
{
	ASSERT_TRUE(mSortedArray.empty());
}

TEST_F(SortedArrayShould, InsertOneElement)
{
	InsertValues({1});
	ASSERT_EQ(mSortedArray.size(), 1);
}

TEST_F(SortedArrayShould, RetrieveCorrectElementValue)
{
	InsertValues({1});
	ASSERT_EQ(mSortedArray[0], 1);
}

TEST_F(SortedArrayShould, ThrowOnExceedingSize)
{
	InsertValues({1, 1, 1, 1, 1});
	EXPECT_THROW(mSortedArray.Insert(0), std::length_error);
}

TEST_F(SortedArrayShould, InsertLesserValueAtFront)
{
	InsertValues({0, -1});
	ASSERT_EQ(mSortedArray[0], -1);
}

TEST_F(SortedArrayShould, InsertGreaterValueAtBack)
{
	InsertValues({1, 0});
	ASSERT_EQ(mSortedArray[1], 1);
}

TEST_F(SortedArrayShould, SortElements)
{
	std::vector<int> inputValues = {1, 23, -3, 1000, -53};
	InsertValues(inputValues);
	std::sort(inputValues.begin(), inputValues.end());
	for (std::size_t i=0; i<inputValues.size(); i++)
	{
		ASSERT_EQ(mSortedArray[i], inputValues[i]);
	}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
