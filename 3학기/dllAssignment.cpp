#include <iostream>
using namespace std;

struct node
{
    string name;
    int id;
    double gpa;
    node *nxt;
};

node *createList()
{
    node *start_ptr = NULL;
    return start_ptr;
}

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

void addNode(node *&start_ptr, string name, int id, float gpa)
{
    node *temp1 = new node;
    temp1->name = name;
    temp1->id = id;
    temp1->gpa = gpa;
    temp1->nxt = NULL;

    if (start_ptr == NULL || id < start_ptr->id)
    {
        temp1->nxt = start_ptr;
        start_ptr = temp1;
    }
    else
    {
        node *temp2 = start_ptr;
        while (temp2->nxt && temp2->nxt->id < id)
        {
            temp2 = temp2->nxt;
        }
        temp1->nxt = temp2->nxt;
        temp2->nxt = temp1;
    }
}

void deleteNode(node *&start_ptr, int id)
{
    if (start_ptr && start_ptr->id == id)
    {
        node *temp = start_ptr;
        start_ptr = start_ptr->nxt;
        delete temp;
        cout << "Node deleted" << endl;
        return;
    }

    node *temp2 = start_ptr;
    while (temp2 && temp2->nxt && temp2->nxt->id != id)
    {
        temp2 = temp2->nxt;
    }

    if (temp2 && temp2->nxt)
    {
        node *temp = temp2->nxt;
        temp2->nxt = temp2->nxt->nxt;
        delete temp;
        cout << "Node deleted" << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }
}

void modifyNode(node *start_ptr, int id)
{
    node *temp = start_ptr;
    while (temp && temp->id != id)
    {
        temp = temp->nxt;
    }

    if (temp == NULL)
    {
        cout << "Node not found" << endl;
    }
    else
    {
        cout << "New name: ";
        cin.ignore();
        getline(cin, temp->name);
        cout << "New GPA: ";
        cin >> temp->gpa;
        cout << "Node modified" << endl;
    }
}

void displayNode(node *start_ptr, int id)
{
    node *temp2 = start_ptr;
    while (temp2 && temp2->id != id)
    {
        temp2 = temp2->nxt;
    }

    if (temp2 == NULL)
    {
        cout << "Node not found" << endl;
    }
    else
    {
        cout << "Name: " << temp2->name << ", ID: " << temp2->id << ", GPA: " << temp2->gpa << endl;
    }
}

void displayList(node *start_ptr)
{
    node *temp = start_ptr;
    while (temp)
    {
        cout << "Name: " << temp->name << ", ID: " << temp->id << ", GPA: " << temp->gpa << endl;
        temp = temp->nxt;
    }
}

void purgeList(node *&start_ptr)
{
    node *temp1 = start_ptr;
    while (temp1)
    {
        node *temp2 = temp1;
        temp1 = temp1->nxt;
        delete temp2;
    }
    start_ptr = NULL;
}

bool checkDuplicateID(node *start_ptr, int id)
{
    node *temp = start_ptr;
    while (temp)
    {
        if (temp->id == id)
        {
            return true;
        }
        temp = temp->nxt;
    }
    return false;
}

bool checkEmpty(node *start_ptr)
{
    return start_ptr == NULL;
}

void checkID(int &id)
{
    cout << "Enter ID (1000-9999): ";
    cin >> id;

    while (id < 1000 || id > 9999)
    {
        cout << "Invalid ID. Please enter a valid ID (1000-9999): ";
        cin >> id;
    }
}

int main()
{
    int choice, id;
    string name;
    double gpa;
    node *start_ptr;

    bool listCreated = false;

    while (true)
    {
        displayMenu();
        cout << "Enter choice: ";
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
                cout << "List does not exist." << endl;
                break;
            }
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            checkID(id);
            if (checkDuplicateID(start_ptr, id) == true)
            {
                cout << "Duplicate ID node not added" << endl;
                break;
            }
            cout << "Enter GPA: ";
            cin >> gpa;
            addNode(start_ptr, name, id, gpa);
            cout << "Node added" << endl;
            break;
        case 3:
            if (listCreated == false)
            {
                cout << "List does not exist." << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            checkID(id);
            deleteNode(start_ptr, id);
            break;
        case 4:
            if (listCreated == false)
            {
                cout << "List does not exist." << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            checkID(id);
            modifyNode(start_ptr, id);
            break;
        case 5:
            if (listCreated == false)
            {
                cout << "List does not exist." << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            checkID(id);
            displayNode(start_ptr, id);
            break;
        case 6:
            if (listCreated == false)
            {
                cout << "List does not exist." << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            displayList(start_ptr);
            break;
        case 7:
            if (listCreated == false)
            {
                cout << "List does not exist." << endl;
                break;
            }
            else if (start_ptr == NULL)
            {
                cout << "List is empty" << endl;
                break;
            }
            purgeList(start_ptr);
            cout << "List purged" << endl;
            break;
        case 8:
            return 0;
        }
    }
}