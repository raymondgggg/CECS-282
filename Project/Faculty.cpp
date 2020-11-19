#include "Faculty.h"
#include <iostream>

Faculty::Faculty(std::string lastName, std::string firstName, std::string id, Sex s, std::string bDay, lvl l, Education ed)
    : Employee {lastName, firstName, id, s, bDay}, l {l}, ed {ed} {
}

Faculty::Faculty(): Employee {"", "", "", F, ""}, l {AS}, ed {} {
}

lvl Faculty::getLvl(){
    return this->l;
}

Education Faculty::getEd(){
    return this->ed;
}

void Faculty::setLvl(lvl l){
    this->l = l;
}

void Faculty::setEducation(Education ed){
    this->ed = ed;
}

double Faculty::monthlyEarnings(){
    if (this->l == AS){
        return FACULTY_MONTHLY_SALARY;
    } 
    else if (this->l == AO){
        return FACULTY_MONTHLY_SALARY * 1.2;
    }
    return FACULTY_MONTHLY_SALARY * 1.4;
}

void Faculty::putData(){
    Employee::putData();
    if (this->l == AS){
        std::cout << "Associate Professor" << std::endl;
    }
    else if (this->l == AO){
        std::cout << "Associate Professor" << std::endl;
    }
    else {
        std::cout << "Full Professor" << std::endl;
    }
    std::cout << "Monthly Salary: " << monthlyEarnings() << std::endl;
}

Faculty::~Faculty(){
}

void Faculty::getData(){
    Employee::getData();
    std::cout << "Enter level of faculty AS(0), AO(1), FU(2): ";
    int level;
    std::cin >> level;
    this->l = static_cast<lvl>(level); // cast the int entered to the corresponding level

    std::string degree {};
    std::string major {};
    int research {};
    std::cout << "Enter the Education of the faculty member: ";
    std::cout << "Enter the degree (Bachelors, Masters, PhD): ";
    std::getline(std::cin, degree);

    std::cout << "Enter the major: ";
    std::getline(std::cin, major);

    std::cout << "Enter the number of research publications: ";
    std::cin >> research;

    Education e (degree, major, research);
    setEducation(e);
}