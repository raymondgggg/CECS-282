#include <iostream>
#include <string>
#include "Employee.h"
Employee::Employee(std::string lastName, std::string firstName, std::string id, Sex sex, std::string bDay)
    :lastName {lastName}, firstName {firstName}, id {id}, sex{sex}, bDay{bDay}{

}

Employee::Employee()
    : lastName{""}, firstName{""}, id{""}, sex{F}, bDay{""}{
}

void Employee::putData(){
    std::cout << "ID Employee number: " << this->id << std::endl;
    std::cout << "Employee Name: " << this->firstName << " " << this->lastName << std::endl;
    std::cout << "Birth Date: " << this->bDay << std::endl;
}

std::string Employee::getLastName(){
    return this->lastName;
}

std::string Employee::getFirstName(){
    return this->firstName;
}

std::string Employee::getID(){
    return this->id;
}

Sex Employee::getSex(){
    return this->sex;
}

std::string Employee::getbDay(){
    return this->bDay;
}

void Employee::setLastName(std::string lastName){
    this->lastName = lastName;
}

void Employee::setFirstName(std::string firstName){
    this->firstName = firstName;
}

void Employee::setID(std::string id){
    this->id = id;
}

void Employee::setSex(Sex s){
    this->sex = s;
}

void Employee::setbDay(std::string bDay){
    this->bDay = bDay;
}