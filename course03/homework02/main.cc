#include <iostream>
#include <string>
#include "date.h"

using namespace cppcourse;

int main(int argc, char** argv)
{
	Date d0;
	d0.Print();
	std::cout << "Valid: " << d0.IsValid() << std::endl;
	Date d1 {3, 12, 2019};
	d1.Print();
	std::cout << "Valid: " << d1.IsValid() << std::endl;

	return 0;
}
