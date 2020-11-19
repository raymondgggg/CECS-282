#include "Staff.h"
#include <iostream>

Staff::Staff(std::string lastName, std::string firstName, std::string id, Sex s, std::string bDay, double hrRate)
    : Employee {lastName, firstName, id, s, bDay}, hrRate {hrRate} {
}

Staff::Staff(): Employee {"", "", "", M, ""}, hrRate {0} {
}

double Staff::getRate(){
    return this->hrRate;
}

void Staff::setRate(double hrRate){
    this->hrRate = hrRate;
}

double Staff::monthlyEarnings(){
    return STAFF_MONTHLY_HOURS_WORKED * this->hrRate;
}

void Staff::putData(){
    Employee::putData();
    std::cout << "Full Time" << std::endl;
    std::cout << "Monthly Salary: " << monthlyEarnings() << std::endl;
}

Staff::~Staff(){

}

void Staff::getData(){
    Employee::getData();
    std::cout << "Enter Hourly Rate: ";
    std::cin >> this->hrRate;
}