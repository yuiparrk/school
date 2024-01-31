/*
The monthly payment on a loan may be calculated by the following formula:

Payment = [ (Rate * (1 + Rate)^N) / (((1 + Rate)^N) - 1) ] * L

Rate is the monthly interest rate, which is the annual interest rate divided by 12. 
 (12 percent annual interest would be 1 percent monthly interest. ) N is the number of payments, 
 and L is the amount of the loan. Write a program that asks for these values then displays a report similar to:
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

double annualinterestrate;
double monthlyinterestrate;
double numberofpayments;
double loan;
double payment;
double value1;
double value2;
double annualinterest;
double monthlyinterest;

cout << "Input the annual interest rate: " << endl;
cin >> annualinterestrate;

cout << "Input the number of payments" << endl;
cin >> numberofpayments;

cout << "Input the amount of the loan" << endl;
cin >> loan;

monthlyinterestrate = annualinterestrate / 12;
monthlyinterest = monthlyinterestrate * 0.01;

value1 = monthlyinterest + 1;
value1 = pow(value1, numberofpayments);
value1 = monthlyinterest * value1;

value2 = monthlyinterest + 1;
value2 = pow(value2, numberofpayments);
value2 = value2 - 1;

payment = value1/value2;
payment = payment * loan;

annualinterest = annualinterestrate * 0.01;
annualinterest = loan * annualinterest;

monthlyinterest = loan * monthlyinterest;

cout << "Annual Interest Rate:" << right << setw(18) << annualinterestrate << "%" << endl;
cout << "Montlhy Interest Rate:" << right << setw(17) << monthlyinterestrate << "%" << endl;
cout << "Number of Payments:" << right << setw(21) << numberofpayments << endl;
cout << "Amount of the Loan:" << right << setw(14) << fixed << setprecision(2) << "$" << loan << endl;
cout << "Annual Interest" << right << setw(20) << fixed << setprecision(2) << "$" << annualinterest << endl;
cout << "Monthly Interest" << right << setw(20) << fixed << setprecision(2) << "$" << monthlyinterest << endl;
cout << "Payment:" << right << setw(26) << fixed << setprecision(2) << "$" << payment;

}