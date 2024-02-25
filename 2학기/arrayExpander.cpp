/*
Array Expander

Write a function that accepts an int array and the array’s size as arguments. The
function should create a new array that is twice the size of the argument array. The
function should copy the contents of the argument array to the new array, and initialize
the unused elements of the second array with 0. The function should return a
pointer to the new array.
*/

#include <iostream>

int *arrayExpander(int array[], int size)
{
    int newSize;
    newSize = size * 2;
    int *newArray = new int[newSize];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    for (int i = size; i < newSize; i++)
    {
        newArray[i] = 0;
    }

    return newArray;
}

int main()
{
    int size;
    std::cout << "Input the size of the array: " << std::endl;
    std::cin >> size;

    int *array = new int[size];
    std::cout << "Input the contents of the array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    int *expandedArray = arrayExpander(array, size);

    for (int i = 0; i < size * 2; i++)
    {
        std::cout << "[" << expandedArray[i] << "] ";
    }

    delete[] array;
    delete[] expandedArray;

    return 0;
}