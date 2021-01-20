#include "linkedlist.h"

#include "gtest/gtest.h"

struct TestStruct
{
public:
	TestStruct(int element) : mValue(element) {mCtor = 1;}
	TestStruct(const TestStruct& other)
	{
		mValue = other.mValue;
		mCtor = other.mCtor;
		++mCopy;
	}
	TestStruct& operator=(TestStruct other) {
		mValue = other.mValue;	
		++mCopy;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& target, const TestStruct& source)
	{
		target << source.mValue;
		return target;
	}

public:
	int mValue;
	int mCtor;
	int mCopy = 0;
};

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

                void FillLinkedListWithEmplace(const std::vector<int>& input)
                {
                        for (size_t i = 0; i < input.size(); ++i)
                        {
                                linkedList.emplace_front(input[i]);
                        }
                }

                void CompareWith(const std::vector<int>& expected)
                {
                        for (size_t i = 0; i < expected.size(); ++i)
                        {
				TestStruct testStruct = linkedList.pop_front();
                                ASSERT_EQ(testStruct.mValue, expected[i]);
                        }
                }
                
		void CompareEmplacedElementsWith(const std::vector<int>& expected)
                {
                        for (size_t i = 0; i < expected.size(); ++i)
                        {
				TestStruct testStruct = linkedList.pop_front();
 				ASSERT_EQ(testStruct.mValue, expected[i]);
 				ASSERT_EQ(testStruct.mCtor, 1);
 				ASSERT_EQ(testStruct.mCopy, 1);
                        }
                }

		LinkedList<TestStruct, Cout<TestStruct>> linkedList;
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

TEST_F(LinkedListTest, ProperEmplace)
{
	int n = 3;
	std::vector<int> input = {3,2,1};
	std::vector<int> expected = {1,2,3};

	CheckLinkedListSizeState(0);

	FillLinkedListWithEmplace(input);
	CheckLinkedListSizeState(n);

	CompareEmplacedElementsWith(expected);
	CheckLinkedListSizeState(0);

	ASSERT_ANY_THROW(linkedList.pop_front());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
