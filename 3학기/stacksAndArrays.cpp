#include <iostream>
using namespace std;

const int maxSize = 99; // adjust max stack size here
int stack[maxSize];
int top = -1; // start array index IT WORKS!!

// print the live stack
void printstack()
{
    cout << "\nCurrent Stack: [ ";
    for (int i = 0; i < top + 1; i++)
    {
        cout << stack[i] << " ";
    }
    cout << "]";
}

// push to stack operation
void push(int element)
{
    if (top < maxSize - 1)
    {
        while (true)
        {

            cout << "Enter the element: ";
            cin >> element;

            if (cin.fail() || element < 0 || element > 99)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // check valid input for no text IT WORKS!!!
                cout << "Invalid input. Please enter an integer between 0 and 99\n";
            }

            else
            {
                top++;
                stack[top] = element;
                cout << "\nPushed " << element << " on the stack\n";
                break;
            }
        }
    }
    else
    {
        cout << "Error overflow, stack is full\n";
    }
}

// print the top of the stack value
void displayTop()
{
    if (top >= 0)
    {
        cout << "The top element is: " << stack[top] << endl;
    }
    else
    {
        cout << "Error underflow, stack is empty";
    }
}

// pop off the stack
void pop()
{
    if (top >= 0)
    {
        cout << "\nPopped " << stack[top] << " off the stack\n";
        top--;
    }
    else
    {
        cout << "Error underflow, stack is empty";
    }
}
// purge the stack
void purge()
{
    top = -1;
    cout << "\nThe stack is purged\n";
}
// print the menu
void printmenu()
{
    cout << "\n\nSelect operation?\n";
    cout << "A. to PUSH a number to the stack\n";
    cout << "B. to POP an integer from the stack\n";
    cout << "C. to output the TOP of the stack\n";
    cout << "D. to PURGE the stack\n";
    cout << "E. to EXIT the Program\n\n";
}

// clearing the terminal so that the print menu text doesn't show up after
void clear_terminal()
{
    int result;
#ifdef _WIN32
    result = system("cls"); // Windows
#else
    result = system("clear"); // macOS
#endif
    if (result != 0)
    {
        cout << "\nError in clearing terminal\n";
    }
}
// main
int main()
{
    int element;
    char choice;

    while (true)
    {
        printmenu();
        cin >> choice;

        switch (choice) // choosing which menu option to run
        {
        case 'A':
        case 'a':
            clear_terminal();
            push(element);
            printstack();
            break;
        case 'B':
        case 'b':
            clear_terminal();
            pop();
            printstack();
            break;
        case 'C':
        case 'c':
            clear_terminal();
            displayTop();
            printstack();
            break;
        case 'D':
        case 'd':
            clear_terminal();
            purge();
            printstack();
            break;
        case 'E':
        case 'e':
            clear_terminal();
            cout << "\nExiting program. Bye Bye\n" // ....for real we done
                 << endl;
            return 0;
        default:
            clear_terminal();
            cout << "Invalid input. Please try again" << endl; // IT works!!!!!
            printstack();
            continue;
        }
    }
}