#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

int main()
{
    int biggest;
    int smallest;
    int average;
    const int numOfTests = 5;
    int input[numOfTests];
    int sum = 0;

    biggest = smallest;
    smallest = biggest;

    std::cout << "Input the 5 test scores" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cin >> input[i];
        sum = sum + input[i];

    }

    biggest = input[0];
    for (int i = 0; i < numOfTests; i++)
    {
        if (input[i] > biggest)
        {
            biggest = input[i];
        }
    }

    smallest = input[0];
    for (int i = 0; i < numOfTests; i++)
    {
        if (input[i] < smallest)
        {
            smallest = input[i];
        }
    }

    std::cout << "Minimum test score: " << smallest << std::endl;
    std::cout << "Maximum test score: " << biggest << std::endl;
    average = sum / numOfTests;
    std::cout << "Average test score: " << average << std::endl;
}