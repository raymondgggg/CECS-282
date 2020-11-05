#ifndef GAMMA_H
#define GAMMA_H
#include <iostream>
using namespace std;

class gamma{
    static int runningTotal;
    int id;
public:
    gamma();
    ~gamma();
    static void showtotal();
    void showid();
};
#endif