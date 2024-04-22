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
    std::cin.ignore();
    getline(std::cin, InventoryRecord.description);
    std::cout << "Quantity: ";
    std::cin >> InventoryRecord.quantity;
    std::cout << "Wholesale Cost: $";
    std::cin >> InventoryRecord.wholesaleCost;
    std::cout << "Retail Cost: $";
    std::cin >> InventoryRecord.retailCost;
    std::cout << "Date Added (MM/DD/YYYY): ";
    std::cin >> InventoryRecord.dateAdded;
    file.write(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
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
    std::cin.ignore();
    getline(std::cin, InventoryRecord.description);
    std::cout << "Quantity: ";
    std::cin >> InventoryRecord.quantity;
    std::cout << "Wholesale Cost: $";
    std::cin >> InventoryRecord.wholesaleCost;
    std::cout << "Retail Cost: $";
    std::cin >> InventoryRecord.retailCost;
    std::cout << "Date Added (MM/DD/YYYY): ";
    std::cin >> InventoryRecord.dateAdded;
    file.seekp(position(input), std::ios::beg);
    file.write(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
}

long position(int input)
{
    return sizeof(InventoryItem) * (input - 1);
}

