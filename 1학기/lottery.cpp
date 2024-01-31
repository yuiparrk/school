/*
Write a program that simulates a lottery. The program should have an array of five integers named winningDigits, with a
randomly generated number in the range of 0 through 9 for each element in the array. The program should ask the user to enter
five digits and should store them in a second integer array named player. The program must compare the corresponding elements
in the two arrays and count how many digits match.

For example, the following shows the winningDigits array and the Player array with the sample numbers stored in each. There are
 two matching digits, elements 2 and 4.

  WinningDigits          [ 7 ] [ 4 ] [ 9 ] [ 1 ] [ 3 ]

  player                 [ 4 ] [ 2 ] [ 9 ] [ 7 ] [ 3 ]

Once the user has entered a set of numbers, the program should display the winning digits and the player's digits and tell how
many digits matched.
*/

#include <iostream>

int main()
{
  const int digits = 5;
  int winningDigits[digits];
  int player[digits];

  srand(time(NULL));

  std::cout << "Enter your 5 digits between 0-9: " << std::endl;
  for (int i = 0; i <= 4; i++)
  {
    std::cin >> player[i];
  }

  for (int i = 0; i <= 4; i++)
  {
    winningDigits[i] = rand() % 10;
  }

  int matchingDigits = 0;
  for (int i = 0; i <= 4; i++)
  {
    if (winningDigits[i] == player[i])
    {
      matchingDigits++;
    }
  }

  std::cout << "Winning Digits: ";
  for (int i = 0; i <= 4; i++)
  {
    std::cout << "[" << winningDigits[i] << "] ";
  }

  std::cout << std::endl << "Player Digits:  ";
  for (int i = 0; i <= 4; i++)
  {
    std::cout << "[" << player[i] << "] ";
  }

  std::cout << std::endl << "Number of Matching Digits: " << matchingDigits;
}