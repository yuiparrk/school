#include <iostream>
#include <string>
using namespace std;

bool checkString(string& input)
{
    int index = 0;

    while (index < input.length())
    {
        char currentCharacter = input[index];

        if (currentCharacter != '0' && currentCharacter != '1')
        {
            cout << "The character " << currentCharacter << " is invalid (Skipped)" << endl;
            index++;
            continue;
        }
index++;
    }
}

int main()
{
    string input;
    cout << "Enter a series of input strings of 0 and 1. (Invalid input will be skipped)";
    cin >> input;

    checkString(input);
}