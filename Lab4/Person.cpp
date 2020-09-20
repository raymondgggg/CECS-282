#include "Person.h"

void Person::setPerson(){
    cout << "Enter name: ";
    cin >> this -> name;
    cout << "Enter Salary: ";
    cin >> this -> salary;
    cout << endl;
}

string Person::getName(){
    return this->name;
}

double Person::getSalary(){
    return this->salary;
}