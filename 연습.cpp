#include <iostream>
#include <string>
using namespace std;

double getSales(const string& divisionName) {
    double sales;
    do {
        cout << "Enter the quarterly sales figure for " << divisionName << ": $";
        cin >> sales;
        if (sales < 0.0) {
            cout << "Invalid input. Sales figure cannot be negative. Please try again." << endl;
        }
    } while (sales < 0.0);
    return sales;
}

void findHighest(double northeastSales, double southeastSales, double northwestSales, double southwestSales) {
    double highestSales = northeastSales;
    string highestDivision = "Northeast";

    if (southeastSales > highestSales) {
        highestSales = southeastSales;
        highestDivision = "Southeast";
    }
    if (northwestSales > highestSales) {
        highestSales = northwestSales;
        highestDivision = "Northwest";
    }
    if (southwestSales > highestSales) {
        highestSales = southwestSales;
        highestDivision = "Southwest";
    }

    cout << "The division with the highest sales is " << highestDivision << " with sales of $" << highestSales << endl;
}

int main() {
    double northeastSales = getSales("Northeast");
    double southeastSales = getSales("Southeast");
    double northwestSales = getSales("Northwest");
    double southwestSales = getSales("Southwest");

    findHighest(northeastSales, southeastSales, northwestSales, southwestSales);

    return 0;
}
