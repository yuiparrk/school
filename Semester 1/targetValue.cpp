/*
2. Write a program using an array that you will declare (SIZE = 10) and populate from input. The program will then ask for a
target value.  Your program will find the number of occurrences that is less than the target value.

Example:

Array Values: [8] [10] [125] [17] [50] [5] [13] [138] [87] [90]

Enter Target Value:  10

Output:

Small Occurrences: 2
*/

#include <iostream>

int main()
{
  int size = 10;
  int input[size];
  int target;
  int targetAmount = 0;

  for (int i = 0; i <= 9; i++)
  {
    std::cin >> input[i];
  }

  std::cout << "Enter Target Value: " << std::endl;
  std::cin >> target;

  for (int i = 0; i <= 9; i++)
  {
    if (input[i] < target)
    {
      targetAmount++;
    }
  }

  std::cout << targetAmount;
}