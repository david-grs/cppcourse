#include "date.h"
#include <iostream>

typedef CppCourse::Homework1::Date Date;

void TestEqual(const Date& date1, const Date& date2)
{
	std::cout << "Test equal: ";
	bool result = date1 == date2;

	std::cout << date1.ToString() << " == " << date2.ToString() << ": " << std::to_string(result) << std::endl;
}

void TestNotEqual(const Date& date1, const Date& date2)
{
	std::cout << "Test not equal: ";
	bool result = date1 != date2;

	std::cout << date1.ToString() << " != " << date2.ToString() << ": " << std::to_string(result) << std::endl;
}

void TestLessThan(const Date& date1, const Date& date2)
{
	std::cout << "Test less than: ";
	bool result = date1 < date2;

	std::cout << date1.ToString() << " < " << date2.ToString() << ": " << std::to_string(result) << std::endl;
}

void TestGreaterThan(const Date& date1, const Date& date2)
{
	std::cout << "Test greater than: ";
	bool result = date1 > date2;

	std::cout << date1.ToString() << " > " << date2.ToString() << ": " << std::to_string(result) << std::endl;
}

void TestLessThanEqual(const Date& date1, const Date& date2)
{
	std::cout << "Test <=: ";
	bool result = date1 <= date2;

	std::cout << date1.ToString() << " <= " << date2.ToString() << ": " << std::to_string(result) << std::endl;
}

void TestGreaterThanEqual(const Date& date1, const Date& date2)
{
	std::cout << "Test >=: ";
	bool result = date1 >= date2;

	std::cout << date1.ToString() << " >= " << date2.ToString() << ": " << std::to_string(result) << std::endl;
}

void TestCompareDates(const Date& base, const Date& lessThanBase, const Date& greaterThanBase)
{
	TestEqual(base, base);
	TestEqual(base, lessThanBase);
	TestEqual(base, greaterThanBase);

	std::cout << std::endl;

	TestNotEqual(base, base);
	TestNotEqual(base, lessThanBase);
	TestNotEqual(base, greaterThanBase);

	std::cout << std::endl;

	TestLessThan(base, base);
	TestLessThan(base, lessThanBase);
	TestLessThan(base, greaterThanBase);

	std::cout << std::endl;

	TestGreaterThan(base, base);
	TestGreaterThan(base, lessThanBase);
	TestGreaterThan(base, greaterThanBase);

	std::cout << std::endl;

	TestLessThanEqual(base, base);
	TestLessThanEqual(base, lessThanBase);
	TestLessThanEqual(base, greaterThanBase);

	std::cout << std::endl;

	TestGreaterThanEqual(base, base);
	TestGreaterThanEqual(base, lessThanBase);
	TestGreaterThanEqual(base, greaterThanBase);
}

int main(int argc, char** argv)
{
	std::cout << "Starting tests" << std::endl;

	Date baseDay {2019, 01, 02};
	Date lessThanBaseDay {2019, 01, 01};
	Date greaterThanBaseDay {2019, 01, 03};

	Date baseMonth {2019, 02, 01};
	Date lessThanBaseMonth {2019, 01, 01};
	Date greaterThanBaseMonth {2019, 03, 01};

	Date baseDayYear {2020, 01, 01};
	Date lessThanBaseDayYear {2019, 01, 01};
	Date greaterThanBaseDayYear {2021, 01, 01};

	std::cout << std::endl << "COMPARE DATES DAY" << std::endl;
	TestCompareDates(baseDay, lessThanBaseDay, greaterThanBaseDay);
	std::cout << std::endl << "COMPARE DATES MONTH" << std::endl;
	TestCompareDates(baseMonth, lessThanBaseMonth, greaterThanBaseMonth);
	std::cout << std::endl << "COMPARE DATES YEAR" << std::endl;
	TestCompareDates(baseDayYear, lessThanBaseDayYear, greaterThanBaseDayYear);
}