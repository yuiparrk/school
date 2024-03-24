//courseID:CIS-265-098WB.2024SP
//name: Daniel Park
//Prof. Wang
//project9
//Due by 3/24/2024

/*
steps
1.Input:
a.search
2.Processing:
a.getline()
b.for ()
3.Output:
a.output
*/

#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string phoneNumbers[] = {
        "Becky Warren, 555-1223",
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Lynn Presnell, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-7676",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939",
        "Ron Palmer, 555-2783"};

    std::string search;
    std::cout << "Enter a name or partial name: ";
    std::getline(std::cin, search);

    for (int i = 0; i < sizeof(phoneNumbers) / sizeof(phoneNumbers[0]); i++)
    {
        if (phoneNumbers[i].find(search) < phoneNumbers[i].length())
        {
            std::cout << phoneNumbers[i] << std::endl;
        }
    }

    return 0;
}
