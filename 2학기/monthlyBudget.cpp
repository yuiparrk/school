/*
Monthly Budget

A student has established the following monthly budget:
Housing 500.00
Utilities 150.00
Household Expenses 65.00
Transportation 50.00
Food 250.00
Medical 30.00
Insurance 100.00
Entertainment 150.00
Clothing 75.00
Miscellaneous 50.00

Write a program that has a MonthlyBudget structure designed to hold each of these
expense categories. The program should pass the structure to a function that asks the
user to enter the amounts spent in each budget category during a month. The program
should then pass the structure to a function that displays a report indicating the
amount over or under in each category, as well as the amount over or under for the
entire monthly budget.
*/

#include <iostream>
#include <string>

struct MonthlyBudget {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

void input(MonthlyBudget &budget) {
    std::cout << "Enter the amounts spent in each budget category during a month:" << std::endl;
    std::cout << "Housing: ";
    std::cin >> budget.housing;
    std::cout << "Utilities: ";
    std::cin >> budget.utilities;
    std::cout << "Household Expenses: ";
    std::cin >> budget.householdExpenses;
    std::cout << "Transportation: ";
    std::cin >> budget.transportation;
    std::cout << "Food: ";
    std::cin >> budget.food;
    std::cout << "Medical: ";
    std::cin >> budget.medical;
    std::cout << "Insurance: ";
    std::cin >> budget.insurance;
    std::cout << "Entertainment: ";
    std::cin >> budget.entertainment;
    std::cout << "Clothing: ";
    std::cin >> budget.clothing;
    std::cout << "Miscellaneous: ";
    std::cin >> budget.miscellaneous;
}

void output(const MonthlyBudget &budget) {
    double totalBudget = 1420;
    double totalExpenses = budget.housing + budget.utilities + budget.householdExpenses + budget.transportation +
                            budget.food + budget.medical + budget.insurance + budget.entertainment +
                            budget.clothing + budget.miscellaneous;
    
    std::cout << "Category           Over/Under" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Housing               " << budget.housing - 500 << std::endl;
    std::cout << "Utilities             " << budget.utilities - 150 << std::endl;
    std::cout << "Household Expenses    " << budget.householdExpenses - 65 << std::endl;
    std::cout << "Transportation        " << budget.transportation - 50 << std::endl;
    std::cout << "Food                  " << budget.food - 250 << std::endl;
    std::cout << "Medical               " << budget.medical - 30 << std::endl;
    std::cout << "Insurance             " << budget.insurance - 100 << std::endl;
    std::cout << "Entertainment         " << budget.entertainment - 150 << std::endl;
    std::cout << "Clothing              " << budget.clothing - 75 << std::endl;
    std::cout << "Miscellaneous         " << budget.miscellaneous - 50 << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Total                 " << totalExpenses - totalBudget << std::endl;
}

int main() {
    MonthlyBudget budget;

    input(budget);
    output(budget);

    return 0;
}
