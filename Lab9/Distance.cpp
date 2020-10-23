#include "Distance.h"

Distance Distance::operator+(const Distance &rhs) const{
    int newFeet {this->feet + rhs.feet};
    float newInches {this->inches + rhs.inches};
    return Distance {newFeet, newInches};
}

Distance operator-(const Distance &lhs, const Distance &rhs){
    int newFeet {lhs.feet - rhs.feet};
    float newInches {lhs.feet - rhs.feet};
    return Distance {newFeet, newInches};
}

std::ostream &operator<<(std::ostream &os, const Distance &obj){
    os << "{Feet: " << obj.feet << ", " << "Inches: " << obj.inches << "}";
    return os;
}

std::istream &operator>>(std::istream &in, Distance &obj){
    std::cout << "Enter Feet: ";
    in >> obj.feet;
    std::cout << "Enter Inches: ";
    in >> obj.inches;
    return in;
}
