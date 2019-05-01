#include "date.h"
#include<vector>
#include<iostream>
#include<string>
#include <exception>
#include <sstream>

const std::vector<int> DAYS_IN_MONTH{{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool Date::IsLeapYear()
{
	if ((mYear % 4 == 0) && (mYear % 100 != 0))
		return true;
	if (mYear % 400 == 0)
		return true;
	return false;
}

void Date::CheckValid()
{
	if ((mYear < 1000) || (mYear > 2999))
		throw std::out_of_range("Invalid date: year must be between 1000 and 2999.");
	if ((mMonth < 1) || (mMonth > 12))
		throw std::out_of_range("Invalid date: month must be between 1 and 12.");

	int maxDaysInMonth = DAYS_IN_MONTH.at(mMonth - 1);
	if ((mMonth == 2) && IsLeapYear())
		++maxDaysInMonth;

	if ((mDay < 1) || (mDay > maxDaysInMonth))
		throw std::out_of_range("Invalid date: days in month out of range.");
}

std::string Date::ToString()
{
	std::ostringstream oss;
	oss << mYear << "-" << mMonth << "-" << mDay;
	std::string var = oss.str();
	return var;
}
