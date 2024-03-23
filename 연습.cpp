#include <iostream>
using namespace std;

int main(){
int *numbers = new int[5];
for (int i = 0; i <= 4; i++)
 *(numbers + i) = i;
cout << numbers[2] << endl;
}