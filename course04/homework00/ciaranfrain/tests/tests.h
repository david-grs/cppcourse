#pragma once

#include "../src/sorted_array.h"
#include <gtest/gtest.h>

class SortedArrayShould: public ::testing::Test
{
public:
	SortedArrayShould();
	void InsertValues(const std::vector<int>&);

protected:
	SortedArray mSortedArray;
	static const int mDefaultMaxSize;
};
