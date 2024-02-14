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

    for (int i = 0; i < months; i++)
    {
        std::cin >> input[i];
        if (input[i] < 0) 
        {
            exit(0);
        }
    }


}