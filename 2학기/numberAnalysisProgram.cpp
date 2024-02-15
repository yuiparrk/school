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
    std::string fileName;
    std::string text;
    //read content into an array
    //display:
    // lowest # + highest # + total # + average #

    std::cout << "What is the file name?: ";
    std::cin >> fileName;

    std::ifstream openFile(fileName);

      while (getline (openFile, text)) {
    std::cout << text << std::endl;
  }
}