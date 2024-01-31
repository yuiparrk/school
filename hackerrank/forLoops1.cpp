#include <iostream>
#include <cstdio>

int main() {
    // Complete the code.
    int a,b;
    std::cin >> a >> b;
    if (a <= b) 
    {
        for (int n = a; n <= b; n++)
        {
            if (n == 1)
            {
                std::cout << "one" << std::endl;
            } else if (n == 2)
            {
                std::cout << "two" << std::endl;
            } else if (n == 3)
            {
                std::cout << "three" << std::endl;
            } else if (n == 4)
            {
                std::cout << "four" << std::endl;
            } else if (n == 5)
            {
                std::cout << "five" << std::endl;
            } else if (n == 6)
            {
                std::cout << "six" << std::endl;
            } else if (n == 7)
            {
                std::cout << "seven" << std::endl;
            } else if (n == 8)
            {
                std::cout << "eight" << std::endl;
            } else if (n == 9)
            {
                std::cout << "nine" << std::endl;
            } else if (n % 2 == 0) {
                std::cout << "even" << std::endl;
            } else {
                std::cout << "odd" << std::endl;
            }
        }
    }
}