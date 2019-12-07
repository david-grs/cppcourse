#include "linkedlist.h"

#include "gtest/gtest.h"

class LinkedListTest : public ::testing::Test 
{
	protected:
		void CheckLinkedListSizeState(int expectedSize)
		{	
			ASSERT_EQ(linkedList.size(), expectedSize);
			if (expectedSize == 0)
				ASSERT_TRUE(linkedList.empty());
			else
				ASSERT_FALSE(linkedList.empty());
		}

                void FillLinkedList(const std::vector<int>& input)
                {
                        for (size_t i = 0; i < input.size(); ++i)
                        {
                                linkedList.push_front(input[i]);
                        }
                }

                void CompareWith(const std::vector<int>& expected)
                {
                        for (size_t i = 0; i < expected.size(); ++i)
                        {
                                ASSERT_EQ(linkedList.pop_front(), expected[i]);
                        }
                }

		LinkedList<int, Cout<int>> linkedList;
};

TEST_F(LinkedListTest, DefaultState)
{
	CheckLinkedListSizeState(0);
	ASSERT_ANY_THROW(linkedList.pop_front());
}

TEST_F(LinkedListTest, InsertAndRead)
{
	int n = 3;
	std::vector<int> input = {3,2,1};
	std::vector<int> expected = {1,2,3};

	CheckLinkedListSizeState(0);

	FillLinkedList(input);
	CheckLinkedListSizeState(n);

	CompareWith(expected);
	CheckLinkedListSizeState(0);

	ASSERT_ANY_THROW(linkedList.pop_front());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
