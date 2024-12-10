/*
1 Create a LL 5
2 Add a node to an empty LL 5
3 Add a node to the front of the LL 5
4 Add a node to the end of the LL 5
5 Show what would happen if an attempt is made to add
a node with an existing ID (duplicate) 5
6 Add a node to somewhere between the firs and last node 5
7 Delete a node from an empty LL (show what happens when an attempt is made to delete a node from an empty LL) 5
8 Delete a node from the front of the LL 5
9 Delete a node from the end of the LL 5
10 Delete a node from somewhere between the firs and last node 5
11 Search for a node which exists in the LL 5
12 Search for a node that does not exist in the LL 5
13 Modify a node 5
14 Purge the LL

*/

#include <iostream>
using namespace std;

int main()
{

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