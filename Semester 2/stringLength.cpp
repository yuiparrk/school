/*
String Length

Write a function that returns an integer and accepts a pointer to a C-string as an argument.
The function should count the number of characters in the string and return
that number. Demonstrate the function in a simple program that asks the user to input
a string, passes it to the function, and then displays the function’s return value.
*/

#include <iostream>
#include <cstring>

int stringLength(const char *input) {
    return std::strlen(input);
}

int main()
{
    int size = 100;
    char input[size];

    std::cout << "Input a string: ";
    std::cin.getline(input, size);

    int output = stringLength(input);
    std::cout << output;

    return 0;
}