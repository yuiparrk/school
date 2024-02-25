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
    for (int i = 0; i < size; i++)
    {
        newArray[i] = i + 1;
    }
    return newArray;
}

int main()
{
    int size = 5;
    int *allocatedArray = allocateArray(size);

    for (int i = 0; i < size; i++)
    {
        std::cout << allocatedArray[i];
    }
    return 0;
}