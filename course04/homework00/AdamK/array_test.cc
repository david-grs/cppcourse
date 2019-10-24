#include "sortedarray.h"

#include "gtest/gtest.h"

class SortedArrayTest : public ::testing::Test 
{
	protected:
		void CheckArraySizeState(size_t expectedSize)
		{	
			ASSERT_EQ(sortedArray.size(), expectedSize);
			ASSERT_EQ(sortedArray.max_size(), expectedMaxSize);
		}

		void FillArray(const std::vector<int>& input)
		{
			for (size_t i = 0; i < input.size(); ++i)
			{
				sortedArray.push_back(input[i]);
			}
		}

		void CompareArray(const std::vector<int>& expected)
		{
			ASSERT_EQ(sortedArray.size(), expected.size());

			for (size_t i = 0; i <= expected.size(); ++i)
			{
				ASSERT_EQ(sortedArray[i], expected[i]); 
			}
		}

		SortedArray sortedArray;
		size_t expectedMaxSize = 32;
};

TEST_F(SortedArrayTest, DefaultState)
{
	CheckArraySizeState(0);
}

TEST_F(SortedArrayTest, SortInsertedElements)
{
	size_t n = 3;
	std::vector<int> input = {3,2,1};
	std::vector<int> expected = {1,2,3};

	FillArray(input);
	CheckArraySizeState(n);
	CompareArray(expected);
}

TEST_F(SortedArrayTest, InsertAboveMaxSize)
{
	size_t n = expectedMaxSize;
	std::vector<int> input(n, 0);

	FillArray(input);
	CheckArraySizeState(n);

	ASSERT_ANY_THROW(sortedArray.push_back(0));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
