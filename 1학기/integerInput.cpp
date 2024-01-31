#include <iostream>

int main() {
    int input;
    int biggest;
    int smallest;

    std::cout << "Input your series of numbers: " << std::endl;
    std::cin >> input;

    if (input == -99) {
        std::cout << "No valid inputs entered" << std::endl;
    }

    biggest = input;
    smallest = input;

    while (true) {

        std::cin >> input;

        if (input == -99) {
            break;
        }

        if (input > biggest) {
            biggest = input;
        }

        if (input < smallest) {
            smallest = input;
        }
    }

    std::cout << "Largest number entered: " << biggest << std::endl;
    std::cout << "Smallest number entered: " << smallest << std::endl;

}