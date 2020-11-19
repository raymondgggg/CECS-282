#include "Partime.h"
#include <iostream>

Partime::Partime(std::string lastName, std::string firstName, std::string id, Sex s, std::string bDay, double hrRate, double hrWk)
    : Staff {lastName, firstName, id, s, bDay, hrRate}, hrWk {hrWk}{
}

Partime::Partime(): Staff {}, hrWk {0}{
}

double Partime::getHrWk(){
    return this->hrWk;
}

void Partime::setHrWk(double hr){
    this->hrWk = hr;
}

double Partime::monthlyEarnings() {
    return this->hrWk * getRate() * 4;
}

void Partime::putData(){
    Employee::putData();
    std::cout << "Hours Worked Per Month: " << this->hrWk * 4 << std::endl;
    std::cout << "Monthly Salary: " << monthlyEarnings() << std::endl;
}

Partime::~Partime(){
    
}

void Partime::getData(){
    Staff::getData();
    std::cout << "Enter hours per week: ";
    std::cin >> this->hrWk;
}