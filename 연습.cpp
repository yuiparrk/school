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

    delete[] array; // Deallocate memory for the original array
    delete[] expandedArray; // Deallocate memory for the expanded array

    return 0;
}
