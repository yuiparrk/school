#include <iostream>
using namespace std;

const int maxSize = 200;
int stack[maxSize];
int top = -1;

void printstack(){
    //cout << stack;
}

void push(int element){
    if (top < maxSize - 1) {
        top++;
        stack[top] = element;
    }
}

void displayTop(){
    if (top >= 0){
        cout << "The top element is: " << stack[top] << endl;
    } else {
        cout << "Error underflow, stack is Empty"; // make this a actual error check if possible
    }
}

void pop(){

}

void purge(){
    top = -1;
    cout << "The stack is purged";
}

void printmenu(){
    cout << "\nSelect operation?\n";
    cout << "A. to PUSH a number to the stack\n";
    cout << "B. to POP an integer from the stack\n";
    cout << "C. to output the TOP of the stack\n";
    cout << "D. to PURGE the stack\n";
    cout << "E. to EXIT the Program\n";
}

//clearing the terminal so that the print menu text doesn't show up after
void clear_terminal() {
    int result;
    #ifdef _WIN32
        result = system("cls");  // Windows
    #else
        result = system("clear");  // macOS
    #endif
        if (result != 0){
        cout << "Erorr in clearing terminal";
        }
}


int main() {
    int element;
    char choice;

    while (true) {
        printmenu();
        cin >> choice;

        switch (choice){
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
                cout << "Exiting program. Bye Bye" << endl;
                return 0;
            defualt

        }
        

    }
}



/*
push function
stack[top + 1] = element

pop function

purge function
idk

main function
choice input
intialize max size, stack, and top = -1

switch loop inside a while loop like last time
try 
    input validation 1-99
    catch
    
*/