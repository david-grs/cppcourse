#include "uniqueptr.h"

#include "gtest/gtest.h"

class UniquePtrTest : public ::testing::Test 
{
	protected:
		void CheckIsEmpty(const UniquePtrInt& uniquePtr)
		{	
			ASSERT_EQ(uniquePtr.get(), nullptr);
			ASSERT_FALSE(uniquePtr);
		}
		
		void CheckIsNotEmpty(const UniquePtrInt& uniquePtr)
		{	
			ASSERT_NE(uniquePtr.get(), nullptr);
			ASSERT_TRUE(uniquePtr);
		}

		void AddArrayData(UniquePtrInt& uniquePtr, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				uniquePtr[i] = i;
				ASSERT_EQ(uniquePtr[i], i);
			}
		}

		void CheckArrayDataIsCorrect(const UniquePtrInt& uniquePtr, size_t n)
		{
			int* data = uniquePtr.get();
			for (size_t i = 0; i < n; ++i)
			{
				ASSERT_EQ(data[i], i);
			}
		}
		
		void CheckArrayDataIsCorrect(const int* data, size_t n)
		{
			for (size_t i = 0; i < n; ++i)
			{
				ASSERT_EQ(data[i], i);
			}
		}

		void FillWithDataAndCheck(UniquePtrInt& uniquePtr, size_t n)
		{
			uniquePtr = make_unique_int(n);
			AddArrayData(uniquePtr, n);

			CheckIsNotEmpty(uniquePtr);
			CheckArrayDataIsCorrect(uniquePtr, n);
		}
};

TEST_F(UniquePtrTest, DefaultState)
{
	UniquePtrInt uniquePtr;
	CheckIsEmpty(uniquePtr);
}

TEST_F(UniquePtrTest, HoldArray)
{
	size_t n = 2;
	UniquePtrInt uniquePtr;
	FillWithDataAndCheck(uniquePtr, n);
}

TEST_F(UniquePtrTest, CheckMoveOperator)
{
	size_t n = 2;
	UniquePtrInt uniquePtr;
	FillWithDataAndCheck(uniquePtr, n);

	UniquePtrInt newUniquePtr;
	newUniquePtr = std::move(uniquePtr);

	CheckIsNotEmpty(newUniquePtr);
	CheckArrayDataIsCorrect(newUniquePtr, n);
}

TEST_F(UniquePtrTest, CheckRelease)
{
	size_t n = 2;
	UniquePtrInt uniquePtr;
	FillWithDataAndCheck(uniquePtr, n);
	
	int* data = uniquePtr.release();
	CheckIsEmpty(uniquePtr);
	CheckArrayDataIsCorrect(data, n);
}

TEST_F(UniquePtrTest, CheckReset)
{
	size_t n = 2;
	UniquePtrInt uniquePtr;
	FillWithDataAndCheck(uniquePtr, n);	

	uniquePtr.reset(nullptr);
	CheckIsEmpty(uniquePtr);
}

TEST_F(UniquePtrTest, CheckSwap)
{
	size_t nA = 2;
	UniquePtrInt uniquePtrA;
	FillWithDataAndCheck(uniquePtrA, nA);	
	
	size_t nB = 2;
	UniquePtrInt uniquePtrB;
	FillWithDataAndCheck(uniquePtrB, nB);	

	uniquePtrA.swap(uniquePtrB);

	CheckIsNotEmpty(uniquePtrA);
	CheckIsNotEmpty(uniquePtrB);

	CheckArrayDataIsCorrect(uniquePtrA, nB);
	CheckArrayDataIsCorrect(uniquePtrB, nA);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
