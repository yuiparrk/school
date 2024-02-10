/*
Winning Division

Write a program that determines which of a company’s four divisions (Northeast, Southeast, Northwest, and Southwest) had the
greatest sales for a quarter. It should include the following two functions, which are called by main.
• double getSales() is passed the name of a division. It asks the user for a division’s quarterly sales figure, validates the input,
 then returns it. It should be called once for each division.
• void findHighest() is passed the four sales totals. It determines which is the largest and prints the name of the high grossing
division, along with its sales figure.

*Input Validation: Do not accept dollar amounts less than $0.00.
*/

#include <iostream>

double getSales(std::string division)
{
    double sales;
    std::cout << "What is the quartery sales figure of the " << division << " division?" << std::endl;
    std::cin >> sales;
    if (sales < 0) {
        std::cout << "Invalid input" << std::endl;
        exit(0);
    }
    return sales;
}

void findHighest(double northEast, double southEast, double northWest, double southWest)
{
    double highest = northEast;
    std::string highestDivision = "Northeast";

    if (southEast > northEast) {
        highest = southEast;
        highestDivision = "southEast";
    }
    if (northWest > southEast) {
        highest = northWest;
        highestDivision = "northWest";
    }
    if (southWest > northWest) {
        highest = southWest;
        highestDivision = "southWest";
    }

    std::cout << "The highest grossing division is the " << highestDivision << "division with $" << highest << " earned.";
}

int main()
{
    double northEast = getSales("Northeast");
    double southEast = getSales("Southeast");
    double northWest = getSales("Northwest");
    double southWest = getSales("Southwest");

    findHighest(northEast, southEast, northWest, southWest);
}