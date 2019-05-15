#include "date.h"

#include <sstream>
#include <array>
#include <stdexcept>

Date::Date() :
	Date(1, 1, 1970)
{}

Date::Date(int day, int month, int year) :
	mDay(day),
	mMonth(month),
	mYear(year)
{
	if (!IsValid())
	{
		throw std::runtime_error("invalid date");
	}
}

/* NOT NEEDED
Date::Date(const Date& other) :
	Date(other.mDay, other.mMonth, other.mYear)
{}

Date& Date::operator=(const Date& other)
{
	mDay = other.mDay;
	mMonth = other.mMonth;
	mYear = other.mYear;

	if (!IsValid())
	{
		throw std::runtime_error("invalid date");
	}

	return *this;
}
*/

bool Date::IsValid() const
{
	static const std::array<int, 12> MonthDays{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return mDay > 0 && mMonth > 0 && mMonth <= 12
			&& mYear != 0 // no year 0 in gregorian calendar
			&& (mDay <= MonthDays[mMonth - 1] || (mDay == 29 && mMonth == 2 && IsLeapYear()));
}

bool Date::IsLeapYear() const
{
	return IsLeapYear(mYear);
}

bool Date::IsLeapYear(int year)
{
	if (year < 1)
	{
		++year;
	}

	return (year % 4 == 0 && year % 100 != 0) || year % 400 ==0;
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
	stream << date.GetDay() << "/" << date.GetMonth() << "/" << date.GetYear();
	return stream;
}
