#include <iostream>
using namespace std;

class Employee {
    private:
    int salary;

    public:
    void setSalary(int s) {
        salary = s;
    }
    int getSalary() {
        return salary;
    }
};

int main() {
    Employee myObj;
    myObj.setSalary(5000);
    cout << myObj.getSalary();
    return 0;
}