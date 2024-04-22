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

bool isValidDate(const std::string &date) {
    // Check if the date has the format MM/DD/YYYY
    if (date.size() != 10 || date[2] != '/' || date[5] != '/')
        return false;

    // Check if all characters are digits
    for (int i = 0; i < 10; ++i) {
        if (i != 2 && i != 5 && !isdigit(date[i]))
            return false;
    }

    return true;
}

void addInventoryRecord(InventoryItem &InventoryRecord, std::fstream &file)
{
    std::cout << "Enter inventory data:" << std::endl;
    std::cout << "Description: ";
    std::cin.ignore();
    getline(std::cin, InventoryRecord.description);
    std::cout << "Quantity: ";
    std::cin >> InventoryRecord.quantity;
    if (InventoryRecord.quantity < 0) {
        std::cerr << "Error: Quantity cannot be negative." << std::endl;
        return;
    }
    std::cout << "Wholesale Cost: $";
    std::cin >> InventoryRecord.wholesaleCost;
    if (InventoryRecord.wholesaleCost < 0) {
        std::cerr << "Error: Wholesale cost cannot be negative." << std::endl;
        return;
    }
    std::cout << "Retail Cost: $";
    std::cin >> InventoryRecord.retailCost;
    if (InventoryRecord.retailCost < 0) {
        std::cerr << "Error: Retail cost cannot be negative." << std::endl;
        return;
    }
    std::cout << "Date Added (MM/DD/YYYY): ";
    std::cin >> InventoryRecord.dateAdded;
    if (!isValidDate(InventoryRecord.dateAdded)) {
        std::cerr << "Error: Invalid date format. Use MM/DD/YYYY." << std::endl;
        return;
    }
    file.seekp(0, std::ios::end);
    file.write(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
}

void changeInventoryRecord(InventoryItem &InventoryRecord, std::fstream &file)
{
    int input;
    std::cout << "Enter the record number to modify: ";
    std::cin >> input;
    file.seekg(sizeof(InventoryRecord) * (input - 1), std::ios::beg);
    file.read(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
    std::cout << "Enter updated inventory details:" << std::endl;
    std::cout << "Description: ";
    std::cin.ignore();
    getline(std::cin, InventoryRecord.description);
    std::cout << "Quantity: ";
    std::cin >> InventoryRecord.quantity;
    if (InventoryRecord.quantity < 0) {
        std::cerr << "Error: Quantity cannot be negative." << std::endl;
        return;
    }
    std::cout << "Wholesale Cost: $";
    std::cin >> InventoryRecord.wholesaleCost;
    if (InventoryRecord.wholesaleCost < 0) {
        std::cerr << "Error: Wholesale cost cannot be negative." << std::endl;
        return;
    }
    std::cout << "Retail Cost: $";
    std::cin >> InventoryRecord.retailCost;
    if (InventoryRecord.retailCost < 0) {
        std::cerr << "Error: Retail cost cannot be negative." << std::endl;
        return;
    }
    std::cout << "Date Added (MM/DD/YYYY): ";
    std::cin >> InventoryRecord.dateAdded;
    if (!isValidDate(InventoryRecord.dateAdded)) {
        std::cerr << "Error: Invalid date format. Use MM/DD/YYYY." << std::endl;
        return;
    }
    file.seekp(sizeof(InventoryRecord) * (input - 1), std::ios::beg);
    file.write(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
}

// Display function remains unchanged
void displayInventoryRecord(InventoryItem &InventoryRecord, std::fstream &file)
{
    int input;
    std::cout << "Enter the record number: ";
    std::cin >> input;
    file.seekg(sizeof(InventoryRecord) * (input - 1), std::ios::beg);
    file.read(reinterpret_cast<char *>(&InventoryRecord), sizeof(InventoryRecord));
    std::cout << "Record #" << input << std::endl;
    std::cout << "Description: " << InventoryRecord.description << std::endl;
    std::cout << "Quantity: " << InventoryRecord.quantity << std::endl;
    std::cout << "Wholesale Cost: $" << InventoryRecord.wholesaleCost << std::endl;
    std::cout << "Retail Cost: $" << InventoryRecord.retailCost << std::endl;
    std::cout << "Date Added: " << InventoryRecord.dateAdded << std::endl;
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
