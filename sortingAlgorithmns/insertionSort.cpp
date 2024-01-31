#include <iostream>

int main()
{
    int array[5] = {12, 11, 13, 5, 6};
    int length = 5;
 
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << "[" << array[i] << "] ";
    }
}