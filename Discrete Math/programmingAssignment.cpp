#include <iostream>
#include <string>
using namespace std;

//boolean function for checking if input contains "1101"
bool checkString(string& input)
{
    //checks from 0 to length of the input
    for (int i = 0; i <= input.length(); i++)
    {
        if (input[i] == '1' && input[i+1] == '1' && input[i+2] == '0' && input[i+3] == '1')
//Instead of checking for invalid characters, the if statement checks if the string "1101" is in the input string sequentially
        {
            return true; //"1101" is in the input
        }
    }
    return false; //"1101" is not in the input
}

int main()
{
    string input; //by using a string as the input, i can check each individual character by it's index
    cout << "Enter a input string: ";
    cin >> input;

    if (checkString(input) == true)
    {
        cout << "String is ACCEPTED";
    } else {
        cout << "String is NOT ACCEPTED";
    }
    return 0;
}