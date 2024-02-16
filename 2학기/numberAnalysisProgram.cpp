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

int main()
{
    const int size = 1000;
    int array[size];
    int num;
    int count = 0;
    double lowest = INT_MAX;
    double highest = INT_MIN;
    double total = 0;
    double average = 0;

    std::string input;
    std::cout << "Enter the name of the file: ";
    std::cin >> input;

    std::ifstream file(input);

    while (file >> num) {
        array[count] = num;
        std::cout << array[count] << std::endl;
        count++;
        total += num;

        if (num < lowest) 
        {
            lowest = num;
        }
        if (num > highest)
        {
            highest = num;
        }
    }

    average = total / count;

    std::cout << lowest << std::endl;
    std::cout << highest << std::endl;
    std::cout << total << std::endl;
    std::cout << average << std::endl;

}