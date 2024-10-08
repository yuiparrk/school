/*
Overloaded Hospital

Write a program that computes and displays the charges for a patient’s hospital stay.
First, the program should ask if the patient was admitted as an in-patient or an outpatient.
If the patient was an in-patient, the following data should be entered:
• The number of days spent in the hospital
• The daily rate
• Hospital medication charges
• Charges for hospital services (lab tests, etc.)
The program should ask for the following data if the patient was an out-patient:
• Charges for hospital services (lab tests, etc.)
• Hospital medication charges

The program should use two overloaded functions to calculate the total charges. One
of the functions should accept arguments for the in-patient data, while the other function
accepts arguments for out-patient information. Both functions should return the
total charges. Input Validation: Do not accept negative numbers for any data.
*/

#include <iostream>

double inPatient(int numOfDays, double dailyRate, double medicationCharges, double hospitalCharges)
{
    double total;

    std::cout << "How long did you spend in the hospital?" << std::endl;
    std::cin >> numOfDays;
    std::cout << "What was the daily rate?" << std::endl;
    std::cin >> dailyRate;
    std::cout << "What were the hospital medication charges?" << std::endl;
    std::cin >> medicationCharges;
    std::cout << "What were the hospital service charges?" << std::endl;
    std::cin >> hospitalCharges;

    if (numOfDays < 0 || dailyRate < 0 || medicationCharges < 0 || hospitalCharges < 0)
    {
        std::cout << "Invalid input" << std::endl;
        exit(0);
    }

    total = (numOfDays * dailyRate) + medicationCharges + hospitalCharges;
    return total;
}

double outPatient(double hospitalCharges, double medicationCharges)
{
    double total;
    std::cout << "What were the hospital service charges?" << std::endl;
    std::cin >> hospitalCharges;
    std::cout << "What were the hospital medication charges?" << std::endl;
    std::cin >> medicationCharges;
    if (hospitalCharges < 0 || medicationCharges < 0)
    {
        std::cout << "Invalid input" << std::endl;
        exit(0);
    }

    total = hospitalCharges + medicationCharges;
    return total;
}

int main()
{
    std::string input;
    std::cout << "Were you admitted as a in-patient or an out-patient? (i/o)" << std::endl;
    std::cin >> input;

    int numOfDays = 0;
    double dailyRate = 0;
    double medicationCharges = 0;
    double hospitalCharges = 0;
    double total = 0;

    if (input == "i")
    {
        total = inPatient(numOfDays, dailyRate, medicationCharges, hospitalCharges);
        std::cout << "Total charges: $" << total << std::endl;
    }
    else if (input == "o")
    {
        total = outPatient(hospitalCharges, medicationCharges);
        std::cout << "Total charges: $" << total << std::endl;
    }
    else
    {
        std::cout << "Invalid input";
    }
}