#include<string>

class Date
{
public:
	Date(int year, int month, int day):
		mYear{year}, mMonth{month}, mDay{day}
	{
		CheckValid();
	}
	std::string ToString();

	bool IsLeapYear();

private:
	int mYear;
	int mMonth;
	int mDay;

	void CheckValid();

//	int mIntRepresentation;

//	int ToIntRepresentation();
//	int FromIntRepresentation();
};
