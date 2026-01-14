/*
Design a class called Date. The class should store a date in three integers: month, day, and year.

There should be member functions to print the date in the following forms:
12/25/10
December 25, 2010
25 December 2010

Demonstrate the class by writing a complete program implementing it.
Input Validation: Do not accept values for the day greater than 31 or less than 1. Do
not accept values for the month greater than 12 or less than 1.
*/

#include <iostream>

class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    void printFormat1()
    {
        std::cout << month << "/" << day << "/" << year % 100 << std::endl;
    }

    void printFormat2()
    {
        std::string months[12] = {"January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December"};
        std::cout << months[month - 1] << " " << day << ", " << year << std::endl;
    }

    void printFormat3()
    {
        std::string months[12] = {"January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December"};
        std::cout << day << " " << months[month - 1] << " " << year << std::endl;
    }
};

int main()
{
    int month;
    int day;
    int year;

    std::cout << "Enter month (1-12): ";
    std::cin >> month;
    if (month < 1 || month > 12)
    {
        std::cout << "Invalid input" << std::endl;
        std::cin >> month;
    }

    std::cout << "Enter day (1-31): ";
    std::cin >> day;
    if (day < 1 || day > 31)
    {
        std::cout << "Invalid input" << std::endl;
        std::cin >> day;
    }

    std::cout << "Enter year: ";
    std::cin >> year;

    Date date(month, day, year);

    date.printFormat1();
    date.printFormat2();
    date.printFormat3();

    return 0;
}
