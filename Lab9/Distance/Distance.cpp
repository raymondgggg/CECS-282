#include "Distance.h"

Distance Distance::operator+(const Distance &rhs) const{
    int newFeet {this->feet + rhs.feet};
    float newInches {this->inches + rhs.inches};
    while(newInches >= 12){
        newFeet++;
        newInches -= 12;
    }
    return Distance {newFeet, newInches};
}

Distance &Distance::operator++(int){
    this->feet++;
    return *this;
}

// Distance &Distance::operator=(const Distance &rhs){
//     this->feet = rhs.feet;
//     this->inches = rhs.inches;
//     return *this;
// }

bool Distance::operator>(const Distance &rhs){
    return (this->feet > rhs.feet) || (this->feet > rhs.feet && this->inches > rhs.inches);
}

Distance operator-(const Distance &lhs, const Distance &rhs){
    int newFeet {lhs.feet - rhs.feet};
    float newInches {lhs.inches - rhs.inches};
    while(newInches < 0){
        newFeet--;
        newInches += 12;
    }
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

Distance operator+(Distance &obj, int y){
    Distance d;
    d.feet = obj.feet + y;
    d.inches = obj.inches;
    return d;
}