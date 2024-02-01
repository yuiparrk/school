#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream MyFile("filename.txt");

    MyFile << "hiiii" << endl;

    cout << "hi" << endl;

    MyFile.close();
}