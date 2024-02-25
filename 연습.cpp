#include <iostream>

int* allocateIntArray(int numElements) {
    // Dynamically allocate an array of integers
    int* newArray = new int[numElements];
    
    return newArray; // Return a pointer to the allocated array
}

int main() {
    int numElements;
    std::cout << "Enter the number of elements to allocate: ";
    std::cin >> numElements;
    
    // Call the function to dynamically allocate the array
    int* dynamicArray = allocateIntArray(numElements);
    
    // Use the allocated array as needed
    
    // Don't forget to deallocate memory to avoid memory leaks
    delete[] dynamicArray;
    
    return 0;
}
