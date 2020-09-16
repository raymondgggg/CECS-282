#include "Person.h"

void Person::setPerson(string name, double salary){
    this->name = name;
    this->salary = salary;
}

string Person::getName(){
    return this->name;
}

double Person::getSalary(){
    return this->salary;
}