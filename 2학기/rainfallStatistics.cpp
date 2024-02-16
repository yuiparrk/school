/*
Rainfall Statistics

Write a program that lets the user enter the total rainfall for each of 12 months into an
array of doubles. The program should calculate and display the total rainfall for the
year, the average monthly rainfall, and the months with the highest and lowest amounts.
Input Validation: Do not accept negative numbers for monthly rainfall figures.
*/

#include <iostream>
#include <climits>
#include <iomanip>

int main()
{
    const int months = 12;
    double input[months] = {0};
    double total = 0;
    double average;
    double highest = INT_MIN;
    int highestMonth = 0;
    double lowest = INT_MAX;
    int lowestMonth = 0;

    std::cout << "Enter the total rainfall for each month: " << std::endl;

    for (int i = 0; i < months; i++)
    {
        std::cout << "Month " << i + 1 << ": " << std::endl;
        std::cin >> input[i];
        if (input[i] < 0)
        {
            std::cout << "Please do not input negative numbers" << std::endl;
            i--;
        }
    }

    for (int i = 0; i < months; i++)
    {
        total = total + input[i];
    }

    average = total / months;

    for (int i = 0; i < months; i++)
    {
        if (input[i] > highest)
        {
            highest = input[i];
            highestMonth = i + 1;
        }

        if (input[i] < lowest)
        {
            lowest = input[i];
            lowestMonth = i + 1;
        }
    }

    std::cout << "Total amount of rainfall: " << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << "Average amount of rainfall each month: " << average << std::endl;
    std::cout << "Highest month of rainfall: Month " << highestMonth << ": " << highest << std::endl;
    std::cout << "Lowest month of rainfall: Month " << lowestMonth << ": " << lowest << std::endl;
    return 0;
}