#include <iostream>

int main()
{
    int random;
    std::string player;
    std::string computer = "placeholder";
    srand(time(NULL));
    random = rand() % 3;

    if (random == 0)
    {
        computer = "r";
    }
    else if (random == 1)
    {
        computer = "p";
    }
    else
    {
        computer = "s";
    }
    
    std::cout << "Player Input: ";
    std::cin >> player;
    std::cout << "Computer Input: " << computer << std::endl;

    if (player == computer)
    {
        std::cout << "Tie" << std::endl;
    }
    if ((player == "r") && (computer == "p"))
    {
        std::cout << "Computer Wins" << std::endl;
    }
    if ((player == "r") && (computer == "s"))
    {
        std::cout << "Player Wins" << std::endl;
    }
    if ((player == "p") && (computer == "r"))
    {
        std::cout << "Player Wins" << std::endl;
    }
    if ((player == "p") && (computer == "s"))
    {
        std::cout << "Computer Wins" << std::endl;
    }
    if ((player == "s") && (computer == "r"))
    {
        std::cout << "Computer Wins" << std::endl;
    }
    if ((player == "s") && (computer == "p"))
    {
        std::cout << "Player Wins" << std::endl;
    }
}