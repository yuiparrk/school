/*
 Write a C++ Program that does the following:

PRECONDITION: LIST size will always be 10 people.

As you can see, there is a file named "invoice1_test1.txt". You are to use this file as your input file for your program. Do the 
following:

1. Sort the file by last name using an array. You can use any of the sorting algorithms that is posted on moodle. You may use the 
string data type to store text data.  NOTE:* If you decide to use the string data type, I will be unavailable for any assistance. 

2. Compute the following:


         a. The total balance due using the BalanceDue column. 

         b. Find the customer(s) with the highest number of rental days.

         c. Find the customer(s) with the highest balance due. 

The OUTPUT file that is listed on the left pane, shows an example of the output that should be printed. Make sure you print the 
output to a file, and not to the console. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Data
{
    string firstName;
    string lastName;
    int daysOfRental;
    double balanceDue;
};

const int arraySize = 10;
void sort(Data arr[], int size);
void print(Data arr[], int size, double totalBalance, Data maxRentalDays[], int countMaxRentalDays, Data maxBalanceDue[], int countMaxBalanceDue);

int main()
{
    ifstream input("invoice1_test1.txt");
    ofstream output("output.txt");
    Data customers[arraySize];

    string header;
    getline(input, header);

    for (int i = 0; i < arraySize; i++)
    {
        input >> customers[i].firstName >> customers[i].lastName >> customers[i].daysOfRental >> customers[i].balanceDue;
    }

    sort(customers, arraySize);

    double totalBalance = 0;
    Data maxRentalDays[arraySize];
    Data maxBalanceDue[arraySize];
    int countMaxRentalDays = 1;
    int countMaxBalanceDue = 1;

    maxRentalDays[0] = customers[0];
    maxBalanceDue[0] = customers[0];

    for (int i = 0; i < arraySize; i++)
    {
        totalBalance = totalBalance + customers[i].balanceDue;

        if (customers[i].daysOfRental > maxRentalDays[0].daysOfRental)
        {
            countMaxRentalDays = 1;
            maxRentalDays[0] = customers[i];
        }
        else if (customers[i].daysOfRental == maxRentalDays[0].daysOfRental)
        {
            maxRentalDays[countMaxRentalDays++] = customers[i];
        }

        if (customers[i].balanceDue > maxBalanceDue[0].balanceDue)
        {
            countMaxBalanceDue = 1;
            maxBalanceDue[0] = customers[i];
        }
        else if (customers[i].balanceDue == maxBalanceDue[0].balanceDue)
        {
            maxBalanceDue[countMaxBalanceDue++] = customers[i];
        }
    }

    print(customers, arraySize, totalBalance, maxRentalDays, countMaxRentalDays, maxBalanceDue, countMaxBalanceDue);

}

void sort(Data arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].firstName > arr[j + 1].firstName)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void print(Data arr[], int size, double totalBalance, Data maxRentalDays[], int countMaxRentalDays, Data maxBalanceDue[], int countMaxBalanceDue)
{
    ofstream output("output.txt");

    output << "LastName FirstName DaysofRental BalanceDue" << endl;
    for (int i = 0; i < size; i++)
    {
        output << arr[i].firstName << " " << arr[i].lastName << " " << arr[i].daysOfRental << " " << fixed << setprecision(2) << arr[i].balanceDue << endl;
    }

    output << endl << "Total Balance Due for file " << totalBalance << endl;

    output << "Customer with highest number of rental day are: ";
    for (int i = 0; i < countMaxRentalDays; i++)
    {
        output << maxRentalDays[i].lastName << " " << maxRentalDays[i].firstName << " ";
    }
output << endl;

    output << "Customer with highest balance due are: ";
    for (int i = 0; i < countMaxBalanceDue; i++)
    {
        output << maxBalanceDue[i].lastName << " " << maxBalanceDue[i].firstName << " ";
    }
    output << endl;
}