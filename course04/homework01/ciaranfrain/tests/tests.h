#pragma once

#include "../src/linked_list.h"
#include <gtest/gtest.h>

class LinkedListShould: public ::testing::Test
{
public:
	void AssertSize(const std::size_t) const;
	void AssertListContent(const std::vector<int>) const;

protected:
	LinkedList mList;
};
