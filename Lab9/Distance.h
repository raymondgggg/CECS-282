#ifndef DISTANCE_H
#define DISTANCE_H
#include <iostream>
class Distance //English Distance class
{
    friend Distance operator-(const Distance &lhs, const Distance &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Distance &obj);
    friend std::istream &operator>>(std::istream &is, Distance &obj);
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

        int getFeet();
        float getInches();

        Distance operator+(const Distance &rhs) const;
};

#endif //DISTANCE_H