#include "date.h"
#include<iostream>
#include<string>


int main()
{
	try
	{
		const Date d{2000,1,32};
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Date d1{2016,4,30};
	std::string isLeapYear = d1.IsLeapYear()?"It is a leap year.": "It is not a leap year.";
	std::cout << isLeapYear << std::endl;
	std::string s = d1.ToString();
	std::cout << s << std::endl;
}
