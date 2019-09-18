#pragma once

#include <string>

namespace CppCourse { namespace Homework1 {

class Date
{
public:
	Date(int year, int month, int day);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	std::string ToString() const;

	bool operator== (const Date& other) const;
	bool operator!= (const Date& other) const;
	bool operator< (const Date& other) const;
	bool operator> (const Date& other) const;
	bool operator<= (const Date& other) const;
	bool operator>= (const Date& other) const;

private:
	int mYear;
	int mMonth;
	int mDay;
};

}};