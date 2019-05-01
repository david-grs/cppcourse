#include "date.h"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	Homework00::Date date{ 04, 05, 1993 };
	std::cout << "The date is " << date << std::endl;

	date.AddDays(100);
	std::cout << "In 100 days from this date it will be " << date << std::endl;

	date.AddDays(900);
	std::cout << "In 1000 days from this date it will be " << date << std::endl;

	date.AddDays(-1000);
	std::cout << "Once again, the date is " << date << std::endl;

	date.AddDays(-1000);
	std::cout << "And 1000 days before it was " << date << std::endl;

	return 0;
}
