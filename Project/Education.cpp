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

void Education::write(std::ostream& out){
    out.write(reinterpret_cast<char *>(degree.size()), sizeof(degree.size()));
    out.write(degree.c_str(), degree.size());

    out.write(reinterpret_cast<char *>(major.size()), sizeof(major.size()));
    out.write(major.c_str(), major.size());

    out.write((char *) &research, sizeof(research));
} 

void Education::read(std::istream& in){
    std::string::size_type len;
    in.read(reinterpret_cast<char *>(&len), sizeof(len));
    degree = std::string(len, '\0');
    in.read(&degree[0], len);

    in.read(reinterpret_cast<char *>(&len), sizeof(len));
    major = std::string(len, '\0');
    in.read(&major[0], len);

    in.read((char *) &research, sizeof(research));
}