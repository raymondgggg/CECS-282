#include "Education.h"

Education::Education(std::string degree, std::string major, int research)
    : degree {degree}, major {major}, research {research}{

}

Education::Education() : Education {"", "", 0} {

}

std::string Education::getDegree(){
    return this->degree;
}

std::string Education::getMajor(){
    return this->major;
}

int Education::getResearch(){
    return this->research;
} 

void Education::setDegree(std::string degree){
    this->degree = degree;
}

void Education::setMajor(std::string major){
    this->major = major;
}

void Education::setResearch(int r){
    this->research = r;
}