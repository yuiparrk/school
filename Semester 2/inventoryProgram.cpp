/*
Inventory Program

Write a program that uses a structure to store the following inventory data in a file:
Item Description
Quantity on Hand
Wholesale Cost
Retail Cost
Date Added to Inventory

The program should have a menu that allows the user to perform the following tasks:
• Add new records to the file.
• Display any record in the file.
• Change any record in the file.

Input Validation: The program should not accept quantities, or wholesale or retail
costs, less than 0. The program should not accept dates that the programmer determines
are unreasonable.
*/

#include <iostream>
#include <fstream>
#include <string>

struct InventoryItem
{
    std::string description;
    int quantity;
    double wholesaleCost;
    double retailCost;
    std::string dateAdded;
};

void addInventoryRecord(InventoryItem &, std::fstream &);
void displayInventoryRecord(InventoryItem &, std::fstream &);
void changeInventoryRecord(InventoryItem &, std::fstream &);
long position(int);

bool dateValidate(const std::string &date)
{
    if (date.size() != 10 || date[2] != '/' || date[5] != '/')
        return false;

    for (int i = 0; i < 10; ++i)
    {
        if (i != 2 && i != 5 && !isdigit(date[i]))
            return false;
    }

    return true;
}

int main()
{
    InventoryItem InventoryRecord;
    int input;
    std::fstream file("inventory.txt", std::ios::in | std::ios::out | std::ios::binary);

    std::cout << "Enter a number:" << std::endl;
    std::cout << "1. Add New Inventory Record" << std::endl;
    std::cout << "2. Display Inventory Record" << std::endl;
    std::cout << "3. Modify Inventory Record" << std::endl;
    std::cin >> input;

    switch (input)
    {
    case 1:
        addInventoryRecord(InventoryRecord, file);
        break;
    case 2:
        displayInventoryRecord(InventoryRecord, file);
        break;
    case 3:
        changeInventoryRecord(InventoryRecord, file);
        break;
    }

    file.close();
    return 0;
}

void addInventoryRecord(InventoryItem &InventoryRecord, std::fstream &file)
{
    file.seekp(0, std::ios::end);
    std::cout << "Enter inventory data:" << std::endl;
    std::cout << "Description: ";
    std::cin >> InventoryRecord.description;
    std::cout << "Quantity: ";
    std::cin >> InventoryRecord.quantity;
    if (InventoryRecord.quantity < 0)
    {
        std::cout << "Error";
        return;
    }
    else
    {
        std::cout << "Wholesale Cost: $";
        std::cin >> InventoryRecord.wholesaleCost;
        if (InventoryRecord.wholesaleCost < 0)
        {
            std::cout << "Error";
            return;
        }
        else
        {
            std::cout << "Retail Cost: $";
            std::cin >> InventoryRecord.retailCost;
            if (InventoryRecord.retailCost < 0)
            {
                std::cout << "Error";
                return;
            }
            else
            {
                std::cout << "Date Added (MM/DD/YYYY): ";
                std::cin >> InventoryRecord.dateAdded;
                if (!dateValidate(InventoryRecord.dateAdded))
                {
                    std::cout << "Invalid Date Format" << std::endl;
                    return;
                }
                else
                {
                    file.write(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
                }
            }
        }
    }
}

void displayInventoryRecord(InventoryItem &InventoryRecord, std::fstream &file)
{
    int input;
    std::cout << "Enter the record number: ";
    std::cin >> input;
    file.seekg(position(input), std::ios::beg);
    file.read(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
    std::cout << "Record #" << input << std::endl;
    std::cout << "Description: " << InventoryRecord.description << std::endl;
    std::cout << "Quantity: " << InventoryRecord.quantity << std::endl;
    std::cout << "Wholesale Cost: $" << InventoryRecord.wholesaleCost << std::endl;
    std::cout << "Retail Cost: $" << InventoryRecord.retailCost << std::endl;
    std::cout << "Date Added: " << InventoryRecord.dateAdded << std::endl;
}

void changeInventoryRecord(InventoryItem &InventoryRecord, std::fstream &file)
{
    int input;
    std::cout << "Enter the record number to modify: ";
    std::cin >> input;
    file.seekg(position(input), std::ios::beg);
    file.read(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
    std::cout << "Enter updated inventory details:" << std::endl;
    std::cout << "Description: ";
    std::cin >> InventoryRecord.description;
    std::cout << "Quantity: ";
    std::cin >> InventoryRecord.quantity;
    if (InventoryRecord.quantity < 0)
    {
        std::cout << "Error";
        return;
    }
    else
    {
        std::cout << "Wholesale Cost: $";
        std::cin >> InventoryRecord.wholesaleCost;
        if (InventoryRecord.wholesaleCost < 0)
        {
            std::cout << "Error";
            return;
        }
        else
        {
            std::cout << "Retail Cost: $";
            std::cin >> InventoryRecord.retailCost;
            if (InventoryRecord.retailCost < 0)
            {
                std::cout << "Error";
                return;
            }
            else
            {
                std::cout << "Date Added (MM/DD/YYYY): ";
                std::cin >> InventoryRecord.dateAdded;
                if (!dateValidate(InventoryRecord.dateAdded))
                {
                    std::cout << "Invalid Date Format" << std::endl;
                    return;
                }
                else
                {
                    file.write(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
                }
            }
        }
    }
}

long position(int input)
{
    return sizeof(InventoryItem) * (input - 1);
}