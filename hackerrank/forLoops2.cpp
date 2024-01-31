#include <iostream>
#include <cstdio>

int main()
{
    int a, b;
    std::string output[11] = {"even", "odd", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::cin >> a >> b;

    for (int n = a; n <= b; n++)
    {
        if (n <= 9 && n >= 1)
        {
            std::cout << output[n + 1] << std::endl;
        }
        else
        {
            std::cout << output[n % 2] << std::endl;
        }
    }
}