#include <iostream>
#include <string>
using namespace std;

bool checkString(string& input)
{
    for (int i = 0; i <= input.length(); i++)
    {
        if (input[i] == '1' && input[i+1] == '1' && input[i+2] == '0' && input[i+3] == '1')
        {
            return true;
        }
    }
    return false;
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
    return 0;
}