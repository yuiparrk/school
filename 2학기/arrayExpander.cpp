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
    int newSize = size * 2;
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
    int array[] = {1, 2, 3, 4, 5};
    int size = 5;

    int *expandedArray = arrayExpander(array, size);

    for (int i = 0; i < size * 2; i++)
    {
        std::cout << "[" << expandedArray[i] << "] ";
    }
}