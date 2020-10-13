#include "cylinderType.h"
#include <iostream>
#include <math.h>

void cylinderType::print() const{
    std::cout << "Base Center: ";
    pointType::print();
    std::cout << std::endl;

    std::cout << "Base Radius: " << getRadius() << std::endl;
    std::cout << "Base Circumference: " << getCircumference() << std::endl;
    std::cout << "Base Area: " << getArea() << std::endl;
    std::cout << "Cylinder Height: " << getHeight() << std::endl;
    std::cout << "Cylinder Surface Area: " << getSurfaceArea() << std::endl;
    std::cout << "Cylinder Volume: " << getVolume() << std::endl;
 }

 void cylinderType::setHeight(double h){
     this->height = h;
 }

 void cylinderType::setBaseCenter(double x, double y){
     pointType::setPoint(x,y);
 }

 void cylinderType::setCenterRadiusHeight(double x, double y, double r, double h){
     pointType::setPoint(x,y);
     circleType::setRadius(r);
     this->height = h;
 }

 double cylinderType::getHeight() const{
     return this->height;
 }

 double cylinderType::getVolume() const{
     return (circleType::getArea() * this->height);
 }

 double cylinderType::getSurfaceArea() const{
     return (2 * M_PI * this->radius * this->height + 2 * circleType::getArea());
 }

 cylinderType::cylinderType(double x, double y, double r, double h) : circleType(x,y,r){
     this-> height = h;
 }


