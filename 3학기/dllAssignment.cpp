#include <iostream>
using namespace std;

struct node
{
    string name;
    int id;
    float gpa;
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

node *createList()
{
    return NULL;
}

void addNode(string name, int id, float gpa)
{
    node *newnode = new node;
    newnode -> name = name;
    newnode -> id = id;
    newnode -> gpa = gpa;
    newnode -> nxt = NULL;

    if (start_ptr == NULL || id < start_ptr -> id)
    {
        newnode -> nxt = start_ptr;
        start_ptr = newnode;
    }
    else
    {
        node *temp2 = start_ptr;
        while (temp2 -> nxt && temp2 -> nxt -> id < id)
        {
            temp2 = temp2 -> nxt;
        }
        newnode -> nxt = temp2 -> nxt;
        temp2 -> nxt = newnode;
    }
}

void deleteNode(int id)
{
    if (start_ptr -> id == id)
    {
        node *temp = start_ptr;
        start_ptr = start_ptr -> nxt;
        delete temp;
        cout << "Node deleted";
        return;
    }

    node *temp2 = start_ptr;
    while (temp2 -> nxt && temp2 -> nxt -> id != id)
    {
        temp2 = temp2 -> nxt;
    }

    if (temp2 -> nxt == NULL)
    {
        cout << "Node not found";
    }
}

void modifyNode(int id)
{
    node *temp2 = start_ptr;
    while (temp2 && temp2 -> id != id)
    {
        temp2 = temp2 -> nxt;
    }

    if (temp2 == NULL)
    {
        cout << "Node not found";
    }
    else
    {
        cout << "New name: ";
        cin.ignore();
        getline(cin, temp2 -> name);
        cout << "New GPA: ";
        cin >> temp2 -> gpa;
        cout << "Node modified";
    }
}

void displayNode(int id)
{
    node *temp2 = start_ptr;
    while (temp2 && temp2 -> id != id)
    {
        temp2 = temp2 -> nxt;
    }

    if (temp2 == NULL)
    {
        cout << "Node not found";
    }
    else
    {
        cout << "Name: " << temp2 -> name << ", ID: " << temp2 -> id << ", GPA: " << temp2 -> gpa << endl;
    }
}


void displayList()
{
    node *temp2 = start_ptr;
    while (temp2)
    {
        cout << "Name: " << temp2 -> name << ", ID: " << temp2 -> id << ", GPA: " << temp2 -> gpa << endl;
        temp2 = temp2 -> nxt;
    }
}

void purgeList()
{
    node *temp2 = start_ptr;
    while (temp2)
    {
        node *temp = temp2;
        temp2 = temp2 -> nxt;
        delete temp;
    }
    start_ptr = NULL;
}

bool checkDuplicateID(int id)
{
    node *temp2 = start_ptr;
    while (temp2)
    {
        if (temp2 -> id == id)
        {
            return true;
        }
        temp2 = temp2 -> nxt;
    }
    return false;
}

bool checkEmpty()
{
    return start_ptr == NULL;
}

void checkID(int &id)
{
    do
    {
        cout << "Enter ID (1000-9999): ";
        cin >> id;
        if (id < 1000 || id > 9999)
        {
            cout << "Invalid ID" << endl;
        }
    } while (id < 1000 || id > 9999);
}

int main()
{
    int choice, id;
    string name;
    float gpa;
    bool listCreated = false;

    while (true)
    {
        displayMenu();
        cout << "Enter choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            start_ptr = createList();
            listCreated = true;
            cout << "List created" << endl;
            break;
        case 2:
            if (listCreated == false)
            {
                cout << "List does not exist;" << endl;
                break;
            }
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            checkID(id);
            if (checkDuplicateID(id))
            {
                cout << "Duplicate ID" << endl;
                break;
            }
            cout << "Enter GPA: ";
            cin >> gpa;
            addNode(name, id, gpa);
            cout << "Node added" << endl;
            break;

        case 3:
            if (listCreated == false)
            {
                cout << "List does not exist;" << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            checkID(id);
            deleteNode(id);
            break;

        case 4:
            if (listCreated == false)
            {
                cout << "List does not exist;" << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            checkID(id);
            modifyNode(id);
            break;

        case 5:
            if (listCreated == false)
            {
                cout << "List does not exist;" << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            checkID(id);
            displayNode(id);
            break;

        case 6:
            if (listCreated == false)
            {
                cout << "List does not exist;" << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            displayList();
            break;
        case 7:
            if (listCreated == false)
            {
                cout << "List does not exist;" << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            purgeList();
            cout << "List purged" << endl;
            break;
        case 8:
            return 0;
        }
    }
}

