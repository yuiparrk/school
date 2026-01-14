/*
2. The colors red, blue, and yellow are known as primary colors because they cannot be made by mixing other colors. 
When you mix two primary colors, you get a secondary color, as shown here:
When you mix red and blue, you get purple.
When you mix red and yellow, you get orange.
When you mix blue and yellow, you get green.
Write a program that prompts the user to enter the names of two primary colors to mix. 
If the user enters anything other than "red", "blue", or "yellow", the program should display an error message. 
Otherwise, the program should display the name of the secondary color that results by mixing two primary colors. 
Make sure to use char[] array to store strings. 
Assignment will be given a 0 if using the "string" data type, you must use a char[] array. 
*/

#include <iostream>
#include <cstring>

int main() {

    char red[20] = "red";
    char blue[20] = "blue";
    char yellow[20] = "yellow";

    char input1[20];
    char input2[20];

    std::cout << "Enter the first primary color: ";
    std::cin >> input1;

    std::cout << "Enter the second primary color: ";
    std::cin >> input2;

    if (
        (strcmp(input1, red) == 0 && strcmp(input2, blue) == 0) || (strcmp(input1, blue) == 0 && strcmp(input2, red) == 0)
    ) {
        std::cout << "Mixing " << input1 << " and " << input2 << " creates the color purple" << std::endl;
    } else if (
        (strcmp(input1, red) == 0 && strcmp(input2, yellow) == 0) || (strcmp(input1, yellow) == 0 && strcmp(input2, red) == 0)
    ) {
        std::cout << "Mixing " << input1 << " and " << input2 << " creates the color orange" << std::endl;
    } else if (
        (strcmp(input1, blue) == 0 && strcmp(input2, yellow) == 0) || (strcmp(input1, yellow) == 0 && strcmp(input2, blue) == 0)
    ) {
        std::cout << "Mixing " << input1 << " and " << input2 << " creates the color green" << std::endl;
    } else {
        std::cout << "Error: please use valid and different primary colors";
    }
}