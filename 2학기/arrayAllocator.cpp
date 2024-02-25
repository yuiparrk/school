/*
Array Allocator

Write a function that dynamically allocates an array of integers. The function should
accept an integer argument indicating the number of elements to allocate. The function
should return a pointer to the array.
*/

#include <iostream>

int main()
{
int size = 5;
int* allocatedArray = allocate(size);
}

int *allocate(int size)
{
    int *newArray = new int[size];
}