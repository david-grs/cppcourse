#include <iostream>
#include <cassert>
#include <sstream>
#include <iomanip>

class Date
{
public:

	Date() : Date(1970, 1, 1) {}

	explicit Date(int year, int month, int day) :
		mYear(year),
		mMonth(month),
		mDay(day)
	{
		ThrowOnInvalidDate();
	}

	int GetYear() const { return mYear; }
	int GetMonth() const { return mMonth; }
	int GetDay() const { return mDay; }

	void SetYear(int year)
	{
		mYear = year;
		ThrowOnInvalidDate();
	}

	void SetMonth(int month)
	{
		mMonth = month;
		ThrowOnInvalidDate();
	}

	void SetDay(int day)
	{
		mDay = day;
		ThrowOnInvalidDate();
	}

private:
	int mYear, mMonth, mDay;

	bool IsValid() const 
	{
		// Edge cases not handled
		return (mYear > 0) && (mMonth > 0 && mMonth <= 12) && (mDay <= 31);
	}

	class InvalidDateException {};

	void ThrowOnInvalidDate() const
	{
		if (not IsValid())
			throw InvalidDateException();
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		std::stringstream ss;
		ss.fill('0');
		ss << std::setw(4) << date.mYear;
		ss << std::setw(2) << date.mMonth;
		ss << std::setw(2) << date.mDay;
		return os << ss.str();
	}
};

int main()
{
	Date defaultDate;
	std::cout << defaultDate << std::endl;

	Date date(1993, 10, 20);
	std::cout << date << std::endl;

	// Will throw 
	Date wrongDate(2015, 13, 20);
}
