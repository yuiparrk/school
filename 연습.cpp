#include <iostream>

int* allocateIntArray(int numElements) {
    // Dynamically allocate memory for the array
    int* arr = new int[numElements];
    return arr;
}

int main() {
    int numElements;
    std::cout << "Enter the number of elements to allocate: ";
    std::cin >> numElements;

    // Call the function to allocate the array
    int* myArray = allocateIntArray(numElements);

    // Example usage: set some values in the array
    for (int i = 0; i < numElements; ++i) {
        myArray[i] = i * 2;
    }

    // Example usage: print the values in the array
    std::cout << "Array elements: ";
    for (int i = 0; i < numElements; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Don't forget to deallocate the memory when done
    delete[] myArray;

    return 0;
}
