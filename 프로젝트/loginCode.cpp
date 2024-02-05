#include <iostream>
#include <fstream>

int main()
{
    std::string inputPassword;
    std::string password;

    std::cout << "Enter your password: " << std::endl;
    std::cin >> inputPassword;
    std::ifstream readFile("loginPasswords.txt");
    getline(readFile, password);

    if (password == inputPassword)
    {
        std::string text;

        std::ofstream writeFile("loginText.txt");
        std::cout << "Input your text: ";
        std::cin >> text;
        writeFile << text;
    }
    else
    {
        std::cout << "Incorrect password" << std::endl;
    }
}
