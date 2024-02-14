#include <iostream>
#include <climits>

int main()
{
    const int months = 12; // const int for fixed number of months
    double input[months] = {0}; // Initialize all elements to 0
    double total = 0; // Initialize total to 0
    double average;
    double highest = INT_MIN;
    int highestMonth = 0; // Initialize highestMonth to 0
    double lowest = INT_MAX;
    int lowestMonth = 0; // Initialize lowestMonth to 0

    std::cout << "Enter the total rainfall for each month: " << std::endl;

    for (int i = 0; i < months; i++) // Corrected loop condition
    {
        std::cout << "Month " << i + 1 << ": " << std::endl;
        std::cin >> input[i];
        if (input[i] < 0) 
        {
            std::cout << "Rainfall cannot be negative. Exiting...\n"; // Inform user about invalid input
            return 1; // Return non-zero value to indicate error
        }
    }

    for (int i = 0; i < months; i++) // Corrected loop condition
    {
        total = total + input[i];
    }

    average = total / months; // Use 'months' variable instead of hardcoding 12

    for (int i = 0; i < months; i++) // Corrected loop condition
    {
        if (input[i] > highest) {
            highest = input[i];
            highestMonth = i + 1; // Adjust for month numbering starting from 1
        }

        if (input[i] < lowest) {
            lowest = input[i];
            lowestMonth = i + 1; // Adjust for month numbering starting from 1
        }
    }

    std::cout << "Total amount of rainfall: " << total << std::endl;
    std::cout << "Average amount of rainfall each month: " << average << std::endl;
    std::cout << "Highest month of rainfall: Month " << highestMonth << ": " << highest << std::endl;
    std::cout << "Lowest month of rainfall: Month " << lowestMonth << ": " << lowest << std::endl;

    return 0; // Indicate successful completion of the program
}
