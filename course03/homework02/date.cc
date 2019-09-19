#include "date.h"
#include <iostream>

namespace cppcourse {

using namespace std;

Date::Date()
	: mDay{1}
	, mMonth{1}
	, mYear{1900} {}

Date::Date(uint8_t day, uint8_t month, uint32_t year)
	: mDay{day}
	, mMonth{month}
	, mYear{year} {}
	
Date Date::AddDays(uint8_t days)
{
return Date{};
}

Date Date::AddMonths(uint8_t months)
{
return Date{};
}

Date Date::AddYears(uint32_t years)
{
return Date{};
}

inline bool LeapYear(uint32_t year)
{
	return year % 4 == 0
		&& year % 100 != 0
		&& year % 400 == 0;
}

inline char GetDaysInMonth(uint32_t year, uint8_t month)
{
	if (month == 2)
		return LeapYear(year) ? 29 : 28;
	return 31 - (month -1) % 7 % 2;
}

bool Date::IsLeapYear()
{
	return LeapYear(mYear);
}


bool Date::IsValidMonth()
{
	return mMonth >= 1 && mMonth <= 12;
}

bool Date::IsValidDay()
{
	return mDay >= 1 && mDay <= GetDaysInMonth(mMonth, mYear);
}

bool Date::IsValid()
{
	return IsValidMonth() && IsValidDay();
}

void Date::Print()
{
	cout << mDay << "-" << mMonth << "-" << mYear << endl;
}

}
