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
    std::cin.ignore(10, '\n');
    std::cout << "Enter Hourly Rate: ";
    std::cin >> this->hrRate;
}

void Staff::write(std::ofstream& out){
    Employee::write(out);
    out.write((char *) &hrRate, sizeof(hrRate));
}

void Staff::read(std::ifstream& in){
    Employee::read(in);
    in.read((char *) &hrRate, sizeof(hrRate)); 
}