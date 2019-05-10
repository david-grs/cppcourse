#include "date.h"

#include <gtest/gtest.h>

#include <iostream>

/*
TEST(Date, Init)
{
	Date d;
	EXPECT_EQ(1, d.GetDay());
	EXPECT_EQ(1, d.GetMonth());
	EXPECT_EQ(1970, d.GetYear());
}

TEST(Date, Invalid)
{
	EXPECT_ANY_THROW(Date(1, 1, 0));
}

class DateTest : public testing::Test
{
public:
	DateTest()
	{

	}

	Date mDate;
};

TEST_F(DateTest, LeapYear)
{

}
*/

int main()
{
	Date d{1,2,2019};
	//std::cout << Date::IsLeapYear(2019) << std::endl;

	Date d2{d};

	Date d3;
	d3 = d;
	std::cout << d2.GetDay() << std::endl;

	return 0;
}

