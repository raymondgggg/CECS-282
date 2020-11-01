#ifndef DISTANCE_H
#define DISTANCE_H
#include <iostream>
class Distance //English Distance class
{
    friend Distance operator-(const Distance &lhs, const Distance &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Distance &obj);
    friend std::istream &operator>>(std::istream &in, Distance &obj);
    friend Distance operator+(Distance &obj, int);
    private:
        int feet;
        float inches;

    public: //constructor (no args)
        Distance() : feet(0), inches(0.0)
        {
        } //constructor (two args)
        Distance(int ft, float in) : feet(ft), inches(in)
        {
        }

        Distance operator+(const Distance &rhs) const;
        Distance &operator++(int);
        // Distance &operator=(const Distance &rhs);
        bool operator>(const Distance &rhs);
}; 
#endif //DISTANCE_H