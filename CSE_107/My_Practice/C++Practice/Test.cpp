#include <iostream>
using namespace std;

class Animal {
    int id;
    string age;
    string name;

public:
    Animal() 
    { 
        cout << "   CONSTRUCTING "<<name << endl; 
    }

    void setname(string name)
    {
        this->name=name;
    }
    Animal(const Animal& other) {
        cout << "---COPY CONSTRUCTING "<<this->name << endl;
        // Copy the data members here if needed
    }
    ~Animal() { cout << "  !!!DESTRUCTING "<<this->name << endl; }
};

Animal process(Animal a) {
    cout << "In Process" << endl;
    Animal b;
    b = a;
    cout<<"Returning "<<endl;
    return b;
}

int main() {
    cout << "First Line" << endl;
    Animal a; // Creates object 'a'
    cout << "Second Line" << endl;
    Animal b = a; // Copy constructor called for 'b' with 'a'
    cout << "Third Line" << endl;
    Animal c = process(b); // Calls 'process' function with 'b'
    cout << "return line" << endl;

    return 0;
}