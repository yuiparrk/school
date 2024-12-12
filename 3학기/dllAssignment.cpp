#include <iostream>
using namespace std;

struct node {
    string name;
    int id;
    double gpa;
    node *nxt;
};

node *start_ptr = NULL;

void displayMenu()
{
    cout << "Menu:" << endl;
    cout << "1. Create list" << endl;
    cout << "2. Add a node" << endl;
    cout << "3. Delete a node" << endl;
    cout << "4. Modify a node" << endl;
    cout << "5. Display a node" << endl;
    cout << "6. Display the list" << endl;
    cout << "7. Purge the list" << endl;
    cout << "8. Exit" << endl;
}

int main() {
    int choice;
    int id;
    string name;
    float gpa;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
        }
    }
}