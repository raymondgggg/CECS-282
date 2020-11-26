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

void Education::write(std::ofstream& out){
    int strLen {degree.length()};
    out.write((char *) &strLen, sizeof(strLen));
    out.write(degree.c_str(), degree.length());

    strLen = major.length();
    out.write((char *) &strLen, sizeof(strLen));
    out.write(major.c_str(), major.length());

    out.write((char *) &research, sizeof(research));
} 

void Education::read(std::ifstream& in){
    int strLen;

    in.read((char *) &strLen, sizeof(strLen));
    degree.resize(strLen);
    in.read((char *) degree.c_str(), strLen);

    in.read((char *) &strLen, sizeof(strLen));
    major.resize(strLen);
    in.read((char *) major.c_str(), strLen);

    in.read((char *) &research, sizeof(research));
}