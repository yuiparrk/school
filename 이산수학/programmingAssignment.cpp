#include <iostream>
#include <string>
using namespace std;

bool checkString(string& input)
{

}

int main()
{
    string input;
    cout << "Enter a series of input strings of 0 and 1. (Invalid input will be skipped)";
    cin >> input;

    if (checkString(input) == true)
    {
        cout << "String is ACCEPTED";
    } else {
        cout << "String is NOT ACCEPTED";
    }

}