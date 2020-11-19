#include <iostream>
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

Employee::~Employee(){

}

void Employee::getData(){
    std::cin.ignore(10, '\n');
    std::cout << "Enter last name: ";
    std::getline(std::cin, this->lastName);
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, this->firstName);
    

    std::cout << "Enter ID: ";
    std::getline(std::cin, this->id);
    

    char gender;
    std::cout << "Enter sex (m or f): ";
    std::cin >> gender;
    std::cin.ignore();

    

    gender = tolower(gender);
    if (gender == 'm')
        this->sex = M;
    else
        this->sex = F;

    std::cout << "Enter birthdate M/D/YYYY: ";
    std::getline(std::cin, this->bDay);
    std::cout << "Base info added. Press enter to add more info." << std::endl;
}