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

	void VerifyItemAtHead(int data)
	{
		EXPECT_EQ(mList.getHead(), data);
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
	VerifyItemAtHead(5);
}

TEST_F(LLTests, PopElement)
{
	mList.pop_front();
	VerifySize(4);
	VerifyItemAtHead(4);
}

TEST_F(LLTests, ReversedList)
{
	VerifyItemAtHead(4);
	mList.reverse();
	VerifySize(4);
	VerifyItemAtHead(1);
}

TEST_F(LLTests, ClearList)
{
	mList.reset();
	VerifySize(0);
}

TEST_F(LLTests, ErrorCase)
{
	EXPECT_THROW(mList.getHead(), std::out_of_range);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}