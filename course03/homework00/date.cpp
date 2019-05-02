#include "date.h"

Date getDate()
    {
        int day;
        int month;
        int year;

        std::cout << "Which day? ";
        std::cin >> day;
        std::cout << "Which month? ";
        std::cin >> month;
        std::cout << "Which year? ";
        std::cin >> year;

        Date date {day, month, year};

        return date;
    }

int main()
{
    Date date1{17,05,1996};
    date1.print();

    Date date2=getDate();
    date2.print();
}
