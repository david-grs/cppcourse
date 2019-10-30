#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "sarray.h"

class SarrayTests : public testing::Test {
public:
	sarray mSortedArray;
	size_t mMaxCap = 32;

	void CheckSizeAndCapacity(size_t n) {
		EXPECT_EQ(mSortedArray.capacity(), mMaxCap);
		EXPECT_EQ(mSortedArray.size(), n);
	}

	void FillAndCheckOrder(const std::vector<int> &v) {
		for (int x : v)
			mSortedArray.push_back(x);

		for (int i = 0; i < mSortedArray.size() - 1; i++)
			ASSERT_TRUE(mSortedArray[i] <= mSortedArray[i + 1]);
	}
};

TEST_F(SarrayTests, Defaults)
{
	EXPECT_TRUE(&mSortedArray);
	CheckSizeAndCapacity(0);
}

TEST_F(SarrayTests, PushBackAndCorrectNumberOfElements)
{
	FillAndCheckOrder({2, 4, 3, 1, 6, 5});
	CheckSizeAndCapacity(6);
}

TEST_F(SarrayTests, ErrorCase)
{
	EXPECT_THROW(mSortedArray[50], std::out_of_range);
}


int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}