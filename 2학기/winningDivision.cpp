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

double getSales();
void findHighest();
double NE, SE, NW, SW;

int main()
{
    getSales();
    std::cout << NE << SE << NW << SW;
}

double getSales()
{
    std::cout << "What is the quartery sales figure of the Northeast division?" << std::endl;
    std::cin >> NE;
    std::cout << "What is the quartery sales figure of the Southeast division?" << std::endl;
    std::cin >> SE;
    std::cout << "What is the quartery sales figure of the Northwest division?" << std::endl;
    std::cin >> NW;
    std::cout << "What is the quartery sales figure of the Southwest division?" << std::endl;
    std::cin >> SW;

    return NE;
    return SE;
    return NW;
    return SW;
}

void findHighest()
{
}