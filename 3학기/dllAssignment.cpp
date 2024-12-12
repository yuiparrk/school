#include <iostream>
using namespace std;

struct node {
    string name;
    int id;
    double gpa;
    node *nxt;
};

node *start_ptr = NULL;

void displayMenu() {
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

void createList() {
    //no idea how to do this
}

void addNode(int id, string name, float gpa) {
    node *temp;
    node *temp2;
    temp = new node;
    cout << "What is the name of the student?" << endl;
    getline(cin, name);
    cout << "What is the student's ID? (4 digit number 1000-9999)" << endl;
    cin >> temp -> id;
    cout << "What is the student's GPA?" << endl;
    cin >> temp -> gpa;
    temp -> nxt = NULL;

    if (start_ptr == NULL) {
        start_ptr = temp;
    } else {
        temp2 = start_ptr;
        //this means list is not empty
        while (temp2 -> nxt != NULL) {
            temp2 = temp2 -> nxt;
        }
        temp2 -> nxt = temp;
    }
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
                //check if list already exists
                createList();
                break;
            case 2:
                //check if list already exists
                addNode(id, name, gpa);
                break;
            case 3:
                //check if list already exists
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
        }
    }
}