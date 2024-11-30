#include <iostream>
#include <string>
using namespace std;

bool checkString(string& input)
{
    int index = 0;
    int sequence = 0;

    while (index < input.length())
    {
        char currentCharacter = input[index];

        if (currentCharacter != '0' && currentCharacter != '1')
        {
            cout << "The character " << currentCharacter << " is invalid. (Skipped)" << endl;
            index++;
            continue;
        }

        if (sequence == 0 && currentCharacter == '1'){
            sequence++;
        } else if (sequence == 1 && currentCharacter == '1'){
            sequence++;
        } else if (sequence == 2 && currentCharacter == '0'){
            sequence++;
        } else if (sequence == 3 && currentCharacter == '1'){
            return true;
        }

        index++;
    }
    return false;
}

int main()
{
    string input;
    cout << "Enter a series of input strings of 0 and 1. (Invalid input will be skipped)" << endl;
    cin >> input;

    if (checkString(input) == true){
        cout << "String is ACCEPTED";
    } else {
        cout << "String is NOT Accepted";
    }
    return 0;
}