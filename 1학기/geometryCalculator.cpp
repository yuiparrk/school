#include <iostream>
#include <cmath>

int main() {

    int userinput;
    double userinput1;
    double userinput2; 
    double area;
    double pi = 3.14159;

    std::cout << "Geometry Calculator" << std::endl;
    std::cout << "1. Calculate the Area of a Circle" << std::endl;
    std::cout << "2. Calculate the Area of a Rectangle" << std::endl;
    std::cout << "3. Calculate the Area of a Triangle" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "Enter your choice (1-4)" << std::endl;
    std::cin >> userinput;

    if (userinput != 1 && userinput != 2 && userinput != 3 && userinput != 4) {
        std::cout << "Please input a valid choice";
        return 0;
    }

    switch (userinput) {
        case 1: {
            std::cout << "Input the radius of the circle: " << std::endl;
            std::cin >> userinput1;
            if (userinput1 < 0) {
                std::cout << "Please input a positive number";
                return 0;
            } else {
                area = pow(userinput1,2);
                area = area * pi;
                std::cout << "The area of the circle is: " << area << std::endl;
                return 0;
            }
        }
        case 2: {
            std::cout << "Input the length of the rectangle: " << std::endl;
            std::cin >> userinput1;
            std:: cout << "Input the width of the rectangle: " << std::endl;
            std::cin >> userinput2;
            if (userinput1 < 0 || userinput2 < 0) {
                std::cout << "Please input a positive number";
                return 0;
            } else {
                area = userinput1 * userinput2;
                std::cout << "The area of the rectangle is: " << area << std::endl;
                return 0;
            }
        }
        case 3: {
            std::cout << "Input the base of the triangle: " << std::endl;
            std::cin >> userinput1;
            std::cout << "Input the height of the triangle" << std::endl;
            std::cin >> userinput2;
            if (userinput1 < 0 || userinput2 < 0) {
                std::cout << "Please input a positive number";
                return 0;
            } else {
                area = (userinput1 * userinput2) * 0.5;
                std::cout << "The area of the triangle is: " << area << std::endl;
                return 0;
            }
        }
        case 4: {
            return 0;
        }
    }

}