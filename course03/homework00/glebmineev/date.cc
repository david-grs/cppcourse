#include "date.h"
#include <iomanip>

namespace Homework00 {

Date::Date(int day, int month, int year)
    : mDay(day), mMonth(month), mYear(year)
{
    if (mMonth < 1 || mMonth > 12) { throw std::runtime_error {"invalid month"}; }
    if (mDay < 1 || mDay > GetDaysInCurrentMonth()) { throw std::runtime_error {"invalid day of month"}; }
}

void Date::AddDays(int days)
{
    mDay += days;
    while (mDay > GetDaysInCurrentMonth())
    {
        mDay -= GetDaysInCurrentMonth();
        mMonth += 1;
        NormalizeMonth();
    }
    while (mDay < 1)
    {
        mMonth -= 1;
        NormalizeMonth();
        mDay += GetDaysInCurrentMonth();
    }
}

bool Date::IsLeapYear() const
{
    if (mYear % 400 == 0) { return true; }
    if (mYear % 100 == 0) { return false; }
    return mYear % 4 == 0;
}

int Date::GetDaysInCurrentMonth() const
{
    static const int daysPerMonth[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mMonth == 2 && IsLeapYear()) return 29;
    return daysPerMonth[mMonth - 1];
}

int Date::GetDaysInCurrentYear() const
{
    return IsLeapYear() ? 366 : 365;
}

void Date::NormalizeMonth()
{
    while (mMonth > 12)
    {
        mMonth -= 12;
        ++mYear;
    }

    while (mMonth < 1)
    {
        mMonth += 12;
        --mYear;
    }
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << std::setw(2) << std::setfill('0') << date.GetDayOfMonth() << '.'
        << std::setw(2) << std::setfill('0') << date.GetMonth() << '.'
        << std::setw(4) << std::setfill('0') << date.GetYear();
    return os;
}

}