#include <iostream>
#include <fstream>

void login() {}

int main()
{
    std::string inputPassword;
    std::string password;

    std::cout << "Enter your password: " << std::endl;
    std::cin >> inputPassword;
    std::ifstream readFile("passwords.txt");
    getline(readFile, password);

    if (password == inputPassword)
    {
        login();
    }
    else
    {
        std::cout << "Incorrect password" << std::endl;
    }

    void login();
    {
        std::string write;

        std::cout << "Enter your text: ";
        std::cin >> write;
        std::ofstream writeFile << write;
    }
}

// have a seperate text file database for usernames and passwords
// link that account to another text file
