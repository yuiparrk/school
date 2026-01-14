/*
1. Write a program that reads 5 values into the array values from input. It will determine the largest and the smallest value
 in the arrays, and print them out to output.
*/

#include <iostream>
#include <climits>

int main()
{
  int arrayNum = 5;
  int input[arrayNum];
  int largest = INT_MIN;
  int smallest = INT_MAX;

  std::cout << "Enter your array: " << std::endl;

  for (int i = 0; i < arrayNum; i++)
  {
    std::cin >> input[i];
    if (input[i] < smallest)
    {
      smallest = input[i];
    }
    if (input[i] > largest)
    {
      largest = input[i];
    }
  }

  std::cout << "Smallest value: " << smallest << std::endl;
  std::cout << "Largest value: " << largest;
}