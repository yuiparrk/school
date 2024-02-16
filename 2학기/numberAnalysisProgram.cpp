/*
Number Analysis Program

Write a program that asks the user for a file name. Assume the file contains a series of
numbers, each written on a separate line. The program should read the contents of the
file into an array and then display the following data:
• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array


The Student CD contains a text file named numbers.txt. that you can use to test the
program.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    const int size = 1000;
    int array[size];
    int file;
    int count = 0;
    double lowest = INT_MAX;
    double highest = INT_MIN;
    double total = 0;
    double average = 0;

    std::string input;
    std::cout << "Enter the name of the file: ";
    std::cin >> input;

    std::ifstream readFile(input);

    while (readFile >> file && count < size)
    {
        array[count] = file;
        count++;
        total += file;

        if (file < lowest)
        {
            lowest = file;
        }
        if (file > highest)
        {
            highest = file;
        }
    }

    average = total / count;

    std::cout << "Lowest number: " << lowest << std::endl;
    std::cout << "Highest number: " << highest << std::endl;
    std::cout << "Total of the numbers: " << total << std::endl;
    std::cout << "Average of the numbers: " << std::fixed << std::setprecision(2) << average << std::endl;
    return 0;
}