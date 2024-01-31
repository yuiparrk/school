/*

Assuming there are no deposits other than the original investment, 
the balance in a savings account after one year may be calculated as:

Amount = Principal * [1 + (Rate/T)] ^ T

Principal is the balance in the savings account, Rate is the interest rate, 
and T is the number of times the interest is compouned during a year (T is 4 if the interest is compounded quarterly).

Write a program that asks for the principal, interest rate, and the number of times the interest is compounded. 

*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double principal;
    double interestrate;
    double compound;
    double amount;
    double interest;

    cout << "Input the principal: " << endl;
    cin >> principal;

    cout << "Input the interest rate: " << endl;
    cin >> interestrate;

    cout << "Input the number of times the interest is compounded: " << endl;
    cin >> compound;

    interest = interestrate * 0.01;

    amount = (1+ (interest/compound));
    amount = pow(amount, compound);
    amount = amount * principal;

    interest = interest * principal;

    cout << "Interest Rate:" << right << setw(18) << interestrate << "%" << endl;
    cout << "Times Compounded:" << right << setw(15) << compound << endl;
    cout << "Principal:" << right << setw(15) << fixed << setprecision(2) << "$" << principal << endl;
    cout << "Interest:" << right << setw(18) << fixed << setprecision(2) << "$" << interest << endl;
    cout << "Amount in Savings:" << right << setw(7) << fixed << setprecision(2) << "$" << amount;

}