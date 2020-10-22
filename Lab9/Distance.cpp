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

int Distance::getFeet(){
    return this->feet;
}

float Distance::getInches(){
    return this->inches;
}