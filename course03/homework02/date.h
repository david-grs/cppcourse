#pragma once
#include <stdint.h>

namespace cppcourse {

class Date
{
public:
	Date();
	Date(uint8_t day, uint8_t month, uint32_t year);
	
	Date AddDays(uint8_t days);
	Date AddMonths(uint8_t months);
	Date AddYears(uint32_t years);

	bool IsLeapYear();
	bool IsValid();

	void Print();

	//TODO: print with formatting.
	//TODO: override the stream operator
	//TODO: override the +/-/== operator

private:
	bool IsValidMonth();
	bool IsValidDay();

	uint8_t mDay;
	uint8_t mMonth;
	uint32_t mYear;
};
}
