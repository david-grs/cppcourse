#ifndef DATE_H
#define DATE_H

class Date
{
public:
    int m_day;
    int m_month;
    int m_year;

    void print()
    {
        std::cout << m_day << "/" << m_month << "/"<< m_year;
    }
};

#endif // DATE_H
