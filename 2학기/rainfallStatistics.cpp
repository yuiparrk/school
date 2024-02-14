/*
Rainfall Statistics

Write a program that lets the user enter the total rainfall for each of 12 months into an
array of doubles. The program should calculate and display the total rainfall for the
year, the average monthly rainfall, and the months with the highest and lowest amounts.
Input Validation: Do not accept negative numbers for monthly rainfall figures.
*/

#include <iostream>

int main()
{
    int months = 12;
    double input[months];
    double total;
    double average;
    double highest = 0;
    int highestMonth;
    double lowest = 0;
    int lowestMonth;

    std::cout << "Enter the total rainfall for each month: " << std::endl;

    for (int i = 1; i <= months; i++)
    {
        std::cout << "Month " << i << ": " << std::endl;
        std::cin >> input[i];
        if (input[i] < 0) 
        {
            exit(0);
        }
    }

    for (int i = 0; i <= months; i++)
    {
        total = total + input[i];
    }
    average = total / 12;

    for (int i = 0; i <= months; i++)
    {
        if (input[i] > highest) {
            highest = input[i];
            highestMonth = i;
        }

        if (input[i] < lowest) {
            lowest = input[i];
            lowestMonth = i;
        }
    }

    std::cout << "Total amount of rainfall: " << total << std::endl;
    std::cout << "Average amount of rainfall each month: " << average << std::endl;
        std::cout << "Highest month of rainfall: Month " << highestMonth << ": " << highest << std::endl;
    std::cout << "Lowest month of rainfall: Month " << lowestMonth << ": " << lowest << std::endl;

}