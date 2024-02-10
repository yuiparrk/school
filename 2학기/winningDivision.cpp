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
#include <string>

double getSales(std::string division)
{
    double sales;
    std::cout << "What is the quartery sales figure of the " << division << " division?" << std::endl;
    std::cin >> sales;
    if (sales < 0) {
        std::cout << "Input a amount higher than 0";
        return 0;
    }
    return sales;
}

void findHighest()
{
    
}

int main()
{
    getSales("Northeast");
    getSales("Southeast");
    getSales("Northwest");
    getSales("Southwest");
}