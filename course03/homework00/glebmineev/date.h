#pragma once

#include <ostream>

namespace Homework00 {

class Date
{
public:
    Date(int day, int month, int year);
    void AddDays(int);
    int GetDayOfMonth() const { return mDay; }
    int GetMonth() const { return mMonth; }
    int GetYear() const { return mYear; }

    bool IsLeapYear() const;
    int GetDaysInCurrentMonth() const;
    int GetDaysInCurrentYear() const;

private:
    void NormalizeMonth();

    int mDay;
    int mMonth;
    int mYear;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

}
