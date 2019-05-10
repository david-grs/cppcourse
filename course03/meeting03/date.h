#pragma once

#include <iosfwd>

class Date
{
public:
	Date();
	explicit Date(int day, int month, int year);

	// rule of zero: no dtor, no copy ctor, no assignment op
	// rule of three:
	//Date(const Date&);
	//Date& operator=(const Date&);

	int GetDay() const { return mDay; }
	int GetMonth() const { return mMonth; }
	int GetYear() const { return mYear; }

	bool IsLeapYear() const;
	static bool IsLeapYear(int);

private:
	bool IsValid() const;

	int mDay;
	int mMonth;
	int mYear;
};

std::ostream& operator<<(std::ostream&, const Date&);
