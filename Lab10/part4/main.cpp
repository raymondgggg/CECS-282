#include "gamma.cpp"
#include <iostream>
using namespace std;

int gamma::runningTotal{0};

int main(){
    cout << "Part 4:" << endl;
    gamma g1;
    gamma::showtotal();
    gamma g2, g3;
    gamma::showtotal();
    g1.showid();
    g2.showid();
    g3.showid();
    cout << "----------end of program----------\n";
    return 0;
}