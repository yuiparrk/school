#include <iostream>
using namespace std;

int const maxSize = 200;
int stack[maxSize];
int top = -1;

void push(){
    
}

void top(){
    if (top >= 0){
        cout << "The top element is: " << stack[top] << endl;
    } else {
        cout << "Error: The stack is empty"; // make this a actual error check if possible
    }
}

void pop(){
    
}

void purge(){
    
}

void printmenu(){
    cout << "\nSelect operation?\n";
    cout << 'A. to PUSH a number to the stack\n';
    cout << 'B. to POP an integer from the stack\n';
    cout << 'C. to output the top of the stack\n':
    cout << 'D. to purge the stack\n';
    cout << 'E. to EXIT the Program\n';
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
    int choice;

    while (true) {
        printmenu();
        cin >> choice;

        switch (choice){
            case 1:
















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