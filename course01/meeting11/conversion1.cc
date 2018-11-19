#include<iostream>
#include <iomanip>

int main()
{
	float f = 1e8;

	while (f > 0)
	{
		std::cout << std::setprecision(10) << f << std::endl;
		--f;
	}

	return 0;
}

