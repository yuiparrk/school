/*

Write a program that reverses the sequence of elements in an array. For example, suppose you have an array containing:

           [1      4    9    16     9       7    4       9    11]

Then the array should be changed to:

          [11     9      4        7        9      16        9      4      1]

Suppose the array data is coming from the user.  Use a loop to populate the array initially.  Write out the resulting
reversed array to the console.

*/

#include <iostream>

int main()
{
  int arrayNum = 50;
  int input[arrayNum];
  int size;

  std::cout << "Input the size of the array: " << std::endl;
  std::cin >> size;
  std::cout << "Input the array: " << std::endl;
  for (int i = 0; i < size; i++)
  {
    std::cin >> input[i]; 
  }

  for (int i = 0, j = size - 1; i <= j; i++, j--) { 
    int temp = input[i]; //입력한 숫자 나중에 스게 보관
    input[i] = input[j]; //첫번째 숫자 자리에 마지막 숫자 교체
    input[j] = temp; //마자막 숫자 자리에 젓번째 숫자 교체
  }

  std::cout << "Reversed array:" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << "[" << input[i] << "] ";
  }
}