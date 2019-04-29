#include <iostream>
#include <string>

class Date
{
public:
	explicit Date(int year, int month, int day) :
		year{year},
		month{month},
		day{day}
	{}

	void toString() {
			std::cout << year << "-" << month << "-" << day << std::endl;
	}

	const int year;
	const int month;
	const int day;
};


int main()
{
	Date date{2019, 1, 12};

	date.toString();

	return 0;
}
