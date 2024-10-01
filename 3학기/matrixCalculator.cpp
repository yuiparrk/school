/*
-------------> TO GET THE CALCULATIONS YOU NEED TO EXIT OUT OF THE PROGRAM (PRESS 6) <-------------
*/

#include <iostream>
#include <iomanip>
#include <fstream>

//define structure
using namespace std;
struct Matrix {
    double a11;
    double a12;
    double a21;
    double a22;
};

//print/format matrix
void print_matrix(ofstream &outfile, string operation, string matrixName1, string matrixName2, Matrix &matrix) {
    outfile << "\nMatrix " << operation << " (Matrix " << matrixName1 << " & " << matrixName2 << ")\n";
    outfile << fixed << setprecision(2);
    outfile << "[    " << matrix.a11;
    outfile << "    " << matrix.a12 << "   ]\n";
    outfile << "[    " << matrix.a21;
    outfile << "    " << matrix.a22 << "   ]\n";
    cout << "Calculation successful. Press 6 to exit program and see calculations stored in matrix.txt\n";
    }

//matrix input
void get_matrix(string &name, Matrix &matrix){
    cout << "Input name of matrix: ";
    cin >> name;
    cout << "Matrix value 1: ";
    cin >> matrix.a11;
    cout << "Matrix value 2: ";
    cin >> matrix.a12;
    cout << "Matrix value 3: ";
    cin >> matrix.a21;
    cout << "Matrix value 4: ";
    cin >> matrix.a22;
}

//scalar value input
double get_scalar(double scalar){
    cout << "Enter the scalar value: ";
    cin >> scalar;
    return scalar;
}

//matrix addition
void calc_sum(Matrix &matrix1, Matrix &matrix2, Matrix &sum){
    sum.a11 = matrix1.a11 + matrix2.a11;
    sum.a12 = matrix1.a12 + matrix2.a12;
    sum.a21 = matrix1.a21 + matrix2.a21;
    sum.a22 = matrix1.a22 + matrix2.a22;
}

//matrix subtraction
void calc_diff(Matrix &matrix1, Matrix &matrix2, Matrix &diff){
    diff.a11 = matrix1.a11 - matrix2.a11;
    diff.a12 = matrix1.a12 - matrix2.a12;
    diff.a21 = matrix1.a21 - matrix2.a21;
    diff.a22 = matrix1.a22 - matrix2.a22;
}

//scalar multiplication
void scalar_mult(double scalar, Matrix &matrix1, Matrix &matrix2, Matrix &k_m){
    int choice;
    cout << "Which matrix would you like to perform scalar multiplication on?\n"; 
    cin >> choice;
    
    if (choice == 1){
        k_m.a11 = scalar * matrix1.a11;
        k_m.a12 = scalar * matrix1.a12;
        k_m.a21 = scalar * matrix1.a21;
        k_m.a22 = scalar * matrix1.a22;
    } else if (choice == 2) {
        k_m.a11 = scalar * matrix2.a11;
        k_m.a12 = scalar * matrix2.a12;
        k_m.a21 = scalar * matrix2.a21;
        k_m.a22 = scalar * matrix2.a22;  
    }
}

//matrix multiplication
void calc_prod(Matrix &matrix1, Matrix &matrix2, Matrix &prod){
    prod.a11 = matrix1.a11 * matrix2.a11 + matrix1.a12 * matrix2.a21;
    prod.a12 = matrix1.a11 * matrix2.a12 + matrix1.a12 * matrix2.a22;
    prod.a21 = matrix1.a21 * matrix2.a11 + matrix1.a22 * matrix2.a21;
    prod.a22 = matrix1.a21 * matrix2.a12 + matrix1.a22 * matrix2.a22;
}

//matrix inverse
void calc_inv(Matrix &matrix1, Matrix &matrix2, Matrix &inv){
    double det;

    int choice;
    cout << "Which matrix would you like to perform matrix inverse on?\n"; 
    cin >> choice;
    
    if (choice == 1){
        det = matrix1.a11 * matrix1.a22 - matrix1.a21 * matrix1.a12;
        inv.a11 = matrix1.a22 / det; 
        inv.a12 = -matrix1.a12 / det;
        inv.a21 = -matrix1.a21 / det;
        inv.a22 = matrix1.a11 / det;
    } else if (choice == 2) {
        det = matrix2.a11 * matrix2.a22 - matrix2.a21 * matrix2.a12;
        inv.a11 = matrix2.a22 / det; 
        inv.a12 = -matrix2.a12 / det;
        inv.a21 = -matrix2.a21 / det;
        inv.a22 = matrix2.a11 / det;  
    }
}

//print selection menu (called in main)
void print_menu(){
    cout << "\nSelect operation?\n";
    cout << "1. Matrix addition\n";
    cout << "2. Matrix subtraction\n";
    cout << "3. Scalar multiplication\n";
    cout << "4. Matrix multiplication\n";
    cout << "5. Inverse of matrix\n";
    cout << "6. Exit\n";
}

//clearing the terminal so that the print menu text doesn't show up after
void clear_terminal() {
    int result;
#ifdef _WIN32
    result = system("cls");  // Windows
#else
    result = system("clear");  // macOS
#endif
    if (result != 0){
      cout << "Erorr in clearing terminal";
    }
}

int main()
{
    ofstream outfile("matrix.txt");

    int choice;
    //intialize individual matrix structures  
    Matrix matrix1, matrix2, sum, diff, prod, inv, k_m;
    //names of matrix and operations (used for printing)
    string matrixName1, matrixName2, sumName = "Addition", diffName = "Subtraction", prodName = "Multiplication";
    string invName = "Inverse", k_mName = "Scalar Multiplication";

    get_matrix(matrixName1, matrix1);
    get_matrix(matrixName2, matrix2);  

    while (true){
        print_menu();
        
        cout <<"\nChoose an operation: ";
        cin >> choice;
        
        switch (choice){
            double scalar;
            case 1:
                clear_terminal();
                calc_sum(matrix1, matrix2, sum);
                print_matrix(outfile, sumName, matrixName1, matrixName2, sum);
                break;
            case 2:
                clear_terminal();
                calc_diff(matrix1, matrix2, diff);
                print_matrix(outfile, diffName, matrixName1, matrixName2, diff);
                break;
            case 3: 
                clear_terminal();
                scalar = get_scalar(scalar);
                scalar_mult(scalar, matrix1, matrix2, k_m);
                print_matrix(outfile, k_mName, matrixName1, matrixName2, k_m);
                break;
            case 4:
                clear_terminal();
                calc_prod(matrix1, matrix2, prod);
                print_matrix(outfile, prodName, matrixName1, matrixName2, prod);
                break;
            case 5:
                clear_terminal();
                calc_inv(matrix1, matrix2, inv);
                print_matrix(outfile, invName, matrixName1, matrixName2, inv);
                break;
            case 6:
                clear_terminal();
                cout << "Exiting program. Bye Bye" << endl;
                return 0;
            default:
                cout << "Invalid input. Please try again." << endl;
                return 1;
        }
    }

    outfile.close();
    return 0;
}