#include <iostream>
#include <cassert>
#include <sstream>
#include <iomanip>

class Date
{
public:
	explicit Date(int year, int month, int day) :
		mYear(year),
		mMonth(month),
		mDay(day)
	{
		assert(IsValid());
	}

	int GetYear() const { return mYear; }
	int GetMonth() const { return mMonth; }
	int GetDay() const { return mDay; }

	void SetYear(int year)
	{
		mYear = year;
		assert(IsValid());
	}

	void SetMonth(int month)
	{
		mMonth = month;
		assert(IsValid());
	}

	void SetDay(int day)
	{
		mDay = day;
		assert(IsValid());
	}

	std::string AsString() const
	{
		std::stringstream ss;
		ss.fill('0');
		ss << std::setw(4) << mYear;
		ss << std::setw(2) << mMonth;
		ss << std::setw(2) << mDay;
		return ss.str();
	};

private:
	int mYear, mMonth, mDay;

	bool IsValid() const 
	{
		// Edge cases not handled
		return (mYear > 0) && (mMonth > 0 && mMonth <= 12) && (mDay <= 31);
	}
};

int main()
{
	Date date(1993, 10, 20);
	std::cout << date.AsString() << std::endl;

	// Will terminate at an assertion 
	Date wrongDate(2015, 13, 20);
}
