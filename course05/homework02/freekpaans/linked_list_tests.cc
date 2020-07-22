#include <iosfwd>
#include <iterator>

#include "gtest/gtest.h"

#include "linked_list.h"

using StrLinkedList = LinkedList<std::string>;

TEST(EmptyListTests, IsEmpty)
{
	StrLinkedList lst;

	ASSERT_TRUE(lst.empty());
}

TEST(EmptyListTests, HasSize0)
{
	StrLinkedList lst;

	ASSERT_EQ(0, lst.size());
}

class SingleItemTests : public ::testing::Test 
{
protected:
	StrLinkedList test_list;
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

	StrLinkedList empty_list;
	StrLinkedList filled_list;
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
	StrLinkedList list1;
	StrLinkedList list2 { list1 };

	list1.push_front("hello");

	ASSERT_TRUE(list2.empty());
}


TEST(CopyTests, CopyCopiesTheElements)
{
	StrLinkedList list1;
	list1.push_front("hello");
	list1.push_front("world");

	StrLinkedList list2 { list1 };

	ASSERT_EQ("world", list2.at(0));
	ASSERT_EQ("hello", list2.at(1));
}

TEST(CopyTests, WhenAddingToANonEmptyTheOtherDoesNotGetAffected)
{
	StrLinkedList list1;
	list1.push_front("world");

	StrLinkedList list2 { list1 };

	list1.push_front("hello");

	ASSERT_EQ("world", list2.front());
}

TEST(AssignmentTests, WhenAddingToAnEmptyTheOtherDoesNotGetAffected)
{
	StrLinkedList list1;
	StrLinkedList list2;

	list2 = list1;

	list1.push_front("hello");

	ASSERT_TRUE(list2.empty());
}

TEST(AssignmentTests, AssignmentCopies)
{
	StrLinkedList list1;
	list1.push_front("hello");
	list1.push_front("world");

	StrLinkedList list2;

	list2 = list1;

	ASSERT_FALSE(list2.empty());
	ASSERT_EQ("world", list2.at(0));
	ASSERT_EQ("hello", list2.at(1));
}

TEST(AssignmentTests, WhenAddingToANonEmptyTheOtherDoesNotGetAffected)
{
	StrLinkedList list1;
	list1.push_front("world");

	StrLinkedList list2;

	list2 = list1;

	list1.push_front("hello");

	ASSERT_EQ("world", list2.front());
}


TEST(IteratorTests, CannotModifyIteratorValue)
{
	StrLinkedList list1;

	list1.push_front("world");
	list1.push_front("hello");

	// wouldn't compile
	// *list1.begin() = "good";
	// list1.begin().mLink->mValue = "good";

	ASSERT_EQ("hello", *list1.begin());
}

TEST(RemoveTests, APopRemovesTheFirstElement)
{
	StrLinkedList list1;

	list1.push_front("hello");
	list1.push_front("wereld");

	list1.pop_front();

	ASSERT_EQ("hello", list1.front());
}

template <typename T>
std::string Format(LinkedList<T> list)
{
	std::ostringstream str;

	std::copy(list.begin(), list.end(), std::ostream_iterator<T>{str});

	return str.str();
}

TEST(RandomAccessTests, InsertAtSecond)
{
	StrLinkedList list1;

	list1.insert_at(0, "hello, ");
	list1.insert_at(1, "good ");
	list1.insert_at(2, "world");

	ASSERT_EQ("hello, good world", Format(list1));
}

TEST(TemplateTests, PushAndFront)
{
	LinkedList<int> list;

	list.push_front(42);

	ASSERT_EQ(list.front(), 42);
}

TEST(TemplateTests, MultipleItemsIntegerList)
{
	LinkedList<int> list;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);

	ASSERT_EQ("321", Format(list));
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
