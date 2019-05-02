#include "date.h"
#include <stdexcept>

namespace CppCourse { namespace Homework1 {

Date::Date(int year, int month, int day)
:	mYear(year),
	mMonth(month),
	mDay(day)
{
	if (mYear < 0)
		throw std::runtime_error("Year is not valid.");

	if (mMonth < 0 || mMonth > 12)
		throw std::runtime_error("Month is not valid.");

	// Ignoring special cases like leap years, or 30 vs 31 etc.
	if (mDay < 0 || mDay > 31)
		throw std::runtime_error("Day is not valid.");
}

int Date::GetYear() const
{
	return mYear;
}

int Date::GetMonth() const
{
	return mMonth;
}

int Date::GetDay() const
{
	return mDay;
}

std::string Date::ToString() const
{
	return std::to_string(mYear) + "-" + std::to_string(mMonth) + "-" + std::to_string(mDay);
}

bool Date::operator== (const Date& other) const
{
	return mYear == other.mYear && mMonth == other.mMonth && mDay == other.mDay;
}

bool Date::operator!= (const Date& other) const
{
	return !(*this == other);
}

bool Date::operator< (const Date& other) const
{
	return *this != other && !(*this > other);
}

bool Date::operator> (const Date& other) const
{
	if (mYear == other.mYear)
	{
		if (mMonth == other.mMonth)
		{
			return mDay > other.mDay;
		}
		else
		{
			return mMonth > other.mMonth;
		}
	}
	else
	{
		return mYear > other.mYear;
	}
}

bool Date::operator<= (const Date& other) const
{
	return !(*this > other);
}

bool Date::operator>= (const Date& other) const
{
	return !(*this < other);
}

}};