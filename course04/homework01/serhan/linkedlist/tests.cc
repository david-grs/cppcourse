#include "linked_list.h"
#include <gtest/gtest.h>

class LLTests : public testing::Test
{
public:
	linked_list mList;

	void VerifySize(size_t size)
	{
		EXPECT_EQ(mList.size(), size);
	}

	void FillList(const std::vector<int>& v)
	{
		for (int x : v)
			mList.push_front(x);
	}

	void VerifyItemAt(size_t index, int data)
	{
		EXPECT_EQ(mList.at(index), data);
	}
};


TEST_F(LLTests, Defaults)
{
	EXPECT_TRUE(&mList);
	VerifySize(0);
}

TEST_F(LLTests, NewElements)
{
	FillList({1, 2, 3, 4, 5});
	VerifySize(5);
	VerifyItemAt(0, 5);
}

TEST_F(LLTests, PopElement)
{
	mList.pop_front();
	VerifySize(4);
	VerifyItemAt(0, 4);
}

TEST_F(LLTests, ReversedList)
{
	VerifyItemAt(0, 4);
	mList.reverse();
	VerifySize(4);
	VerifyItemAt(0, 1);
}

TEST_F(LLTests, ClearList)
{
	mList.reset();
	VerifySize(0);
}

TEST_F(LLTests, ErrorCase)
{
	EXPECT_THROW(mList.at(10), std::out_of_range);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}