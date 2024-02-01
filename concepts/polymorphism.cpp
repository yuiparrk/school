#include <iostream>
using namespace std;

//base class
class Animal {
    public: 
    void animalSound(){
        cout << "The animal makes a sound" << endl;
    }
};

//derived class

class Pig: public Animal {
    public:
    void animalSound() {
        cout << "The pig says oink" << endl;
    }
};

int main() {
    Animal myAnimal;
    Pig myPig;
    
    myAnimal.animalSound();
    myPig.animalSound();
//using same function with different things idk where this would be useful prob dont understand fully
}