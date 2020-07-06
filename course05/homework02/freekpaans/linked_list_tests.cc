#include <iosfwd>
#include <iterator>

#include "gtest/gtest.h"

#include "linked_list.h"

TEST(EmptyListTests, IsEmpty)
{
	LinkedList lst;

	ASSERT_TRUE(lst.empty());
}

TEST(EmptyListTests, HasSize0)
{
	LinkedList lst;

	ASSERT_EQ(0, lst.size());
}

class SingleItemTests : public ::testing::Test 
{
protected:
	LinkedList test_list;
};

TEST_F(SingleItemTests, IsNotEmpty)
{
	test_list.push_front("hello, world");

	ASSERT_FALSE(test_list.empty());
}

TEST_F(SingleItemTests, HasSize1)
{
	test_list.push_front("hello, world");

	ASSERT_EQ(1, test_list.size());
}


TEST_F(SingleItemTests, FrontRetrievesTheItem)
{
	test_list.push_front("hello");

	ASSERT_EQ("hello", test_list.front());
}


TEST_F(SingleItemTests, OfEmptyStringIsNotEmpty)
{
	test_list.push_front("");

	ASSERT_FALSE(test_list.empty());
}

class MultipleItemTests : public ::testing::Test
{
protected:
	MultipleItemTests()
	{
		filled_list.push_front("hello, ");
		filled_list.push_front("world");
	}

	LinkedList empty_list;
	LinkedList filled_list;
};

TEST_F(MultipleItemTests, FrontRetrievesFirstItem)
{
	empty_list.push_front("hello");
	empty_list.push_front("world");

	ASSERT_EQ("world", empty_list.front());
}


TEST_F(MultipleItemTests, AtRetrievesCorrectItem)
{
	empty_list.push_front("hello");
	empty_list.push_front("world");

	ASSERT_EQ("hello", empty_list.at(1));
}

TEST_F(MultipleItemTests, ThreeItems)
{
	empty_list.push_front("hello");
	empty_list.push_front("great");
	empty_list.push_front("world");

	ASSERT_EQ("world", empty_list.at(0));
	ASSERT_EQ("great", empty_list.at(1));
	ASSERT_EQ("hello", empty_list.at(2));
}

TEST_F(MultipleItemTests, Empty)
{
	ASSERT_FALSE(filled_list.empty());
}

TEST_F(MultipleItemTests, Size)
{
	ASSERT_EQ(2, filled_list.size());
}

TEST(CopyTests, WhenAddingToAnEmptyTheOtherDoesNotGetAffected)
{
	LinkedList list1;
	LinkedList list2 { list1 };

	list1.push_front("hello");

	ASSERT_TRUE(list2.empty());
}


TEST(CopyTests, CopyCopiesTheElements)
{
	LinkedList list1;
	list1.push_front("hello");
	list1.push_front("world");

	LinkedList list2 { list1 };

	ASSERT_EQ("world", list2.at(0));
	ASSERT_EQ("hello", list2.at(1));
}

TEST(CopyTests, WhenAddingToANonEmptyTheOtherDoesNotGetAffected)
{
	LinkedList list1;
	list1.push_front("world");

	LinkedList list2 { list1 };

	list1.push_front("hello");

	ASSERT_EQ("world", list2.front());
}

TEST(AssignmentTests, WhenAddingToAnEmptyTheOtherDoesNotGetAffected)
{
	LinkedList list1;
	LinkedList list2;

	list2 = list1;

	list1.push_front("hello");

	ASSERT_TRUE(list2.empty());
}

TEST(AssignmentTests, AssignmentCopies)
{
	LinkedList list1;
	list1.push_front("hello");
	list1.push_front("world");

	LinkedList list2;

	list2 = list1;

	ASSERT_FALSE(list2.empty());
	ASSERT_EQ("world", list2.at(0));
	ASSERT_EQ("hello", list2.at(1));
}

TEST(AssignmentTests, WhenAddingToANonEmptyTheOtherDoesNotGetAffected)
{
	LinkedList list1;
	list1.push_front("world");

	LinkedList list2;

	list2 = list1;

	list1.push_front("hello");

	ASSERT_EQ("world", list2.front());
}


TEST(IteratorTests, CannotModifyIteratorValue)
{
	LinkedList list1;

	list1.push_front("world");
	list1.push_front("hello");

	// wouldn't compile
	// *list1.begin() = "good";
	// list1.begin().mLink->mValue = "good";

	ASSERT_EQ("hello", *list1.begin());
}

TEST(RemoveTests, APopRemovesTheFirstElement)
{
	LinkedList list1;

	list1.push_front("hello");
	list1.push_front("wereld");

	list1.pop_front();

	ASSERT_EQ("hello", list1.front());
}

TEST(RandomAccessTests, InsertAtSecond)
{
	LinkedList list1;

	list1.insert_at(0, "hello, ");
	list1.insert_at(1, "good ");
	list1.insert_at(2, "world");

	std::ostringstream str;

	std::copy(list1.begin(), list1.end(), std::ostream_iterator<std::string>{str});

	ASSERT_EQ("hello, good world", str.str());
}


//TODOS
// TEST(RandomAccessTests, DeleteAtSecond)
// {
// 	LinkedList list1;

// 	list1.insert_at(0, "hello, ");
// 	list1.insert_at(1, "good ");
// 	list1.insert_at(2, "world");

// 	list1.delete_at(1);

// 	std::ostringstream str;

// 	std::copy(list1.begin(), list1.end(), std::ostream_iterator<std::string>{str});

// 	ASSERT_EQ("hello, world", str.str());
// }

// TEST(RandomAccessTests, DeleteAtFirst)
// {
// 	LinkedList list1;

// 	list1.insert_at(0, "hello, ");
// 	list1.insert_at(1, "good ");
// 	list1.insert_at(2, "world");

// 	list1.delete_at(0);

// 	std::ostringstream str;

// 	std::copy(list1.begin(), list1.end(), std::ostream_iterator<std::string>{str});

// 	ASSERT_EQ("good world", str.str());
// }
