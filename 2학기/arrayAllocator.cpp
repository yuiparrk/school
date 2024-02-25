/*
Array Allocator

Write a function that dynamically allocates an array of integers. The function should
accept an integer argument indicating the number of elements to allocate. The function
should return a pointer to the array.
*/

#include <iostream>

int *allocateArray(int size)
{
    int *newArray = new int[size];

    std::cout << "Input the contents of the array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> newArray[i];
    }

    return newArray;
}

int main()
{
    int size;

    std::cout << "Input the size of the array: " << std::endl;
    std::cin >> size;
    
    int *allocatedArray = allocateArray(size);

    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << allocatedArray[i] << "] ";
    }

    return 0;
}