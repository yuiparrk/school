#include <iostream>

int main()
{   
    int random;
    std::string player;
    int computer;
    srand(time(NULL));
    random = rand() % 3;

    computer = random;

    std::cout << random;
    std::cout << computer;

    switch (computer)
    {
    case 0:
        computer = 10;
    case 1:
        computer = 20;
    case 2:
        computer = 30;
    }

    std::cout << computer;
}