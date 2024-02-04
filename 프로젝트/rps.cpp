#include <iostream>

int main()
{
    std::string userInput1;
    std::string userInput2;

    std::cout << "Player 1 Input: " << std::endl;
    std::cin >> userInput1;
    std::cout << "Player 2 Input: " << std::endl;
    std::cin >> userInput2;

    if (userInput1 == userInput2)
    {
        std::cout << "Tie" << std::endl;
    }
    if ((userInput1 == "r") && (userInput2 == "p"))
    {
        std::cout << "Player 2 Wins" << std::endl;
    }
    if ((userInput1 == "r") && (userInput2 == "s"))
    {
        std::cout << "Player 1 Wins" << std::endl;
    }
    if ((userInput1 == "p") && (userInput2 == "r"))
    {
        std::cout << "Player 1 Wins" << std::endl;
    }
    if ((userInput1 == "p") && (userInput2 == "s"))
    {
        std::cout << "Player 2 Wins" << std::endl;
    }
    if ((userInput1 == "s") && (userInput2 == "r"))
    {
        std::cout << "Player 2 Wins" << std::endl;
    }
    if ((userInput1 == "s") && (userInput2 == "p"))
    {
        std::cout << "Player 1 Wins" << std::endl;
    }
}