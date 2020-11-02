#ifndef TIME_12_H
#define TIME_12_H
#include <iostream>
using namespace std;

class time12
{
private:
    bool pm;  //true = pm, false = am
    int hrs;  //1 to 12
    int mins; //0 to 59
public:       //no-arg constructor
    time12() : pm(true), hrs(0), mins(0)
    {
    }
    //3-arg constructor
    time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m)
    {
    }
    void display() const //format: 11:59 p.m.
    {
        cout << hrs << ':';
        if (mins < 10)
            cout << '0'; //extra zero for "01"
        cout << mins << ' ';
        string am_pm = pm ? "p.m." : "a.m.";
        cout << am_pm;
    }

};

#endif