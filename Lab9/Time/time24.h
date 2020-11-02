#ifndef TIME_24_H
#define TIME_24_H
#include <iostream>
#include "time12.h"
using namespace std;

class time24
{
private:
    int hours;   //0 to 23
    int minutes; //0 to 59
    int seconds; //0 to 59
public:          //no-arg constructor
    time24() : hours(0), minutes(0), seconds(0)
    {
    }
    time24(int h, int m, int s) : //3-arg constructor
                                  hours(h), minutes(m), seconds(s)
    {
    }
    void display() const //format: 23:15:01
    {
        if (hours < 10)
            cout << '0';
        cout << hours << ':';
        if (minutes < 10)
            cout << '0';
        cout << minutes << ':';
        if (seconds < 10)
            cout << '0';
        cout << seconds;
    }

    operator time12(){
        int hrs {this->hours % 12};
        if (hrs == 0)
            hrs = 12;
        int mins {this->minutes};
        bool pm {false};
        if (this->hours >= 12)
            pm = true;
        return time12 {pm, hrs, mins};
    }
};

#endif //TIME_24_H