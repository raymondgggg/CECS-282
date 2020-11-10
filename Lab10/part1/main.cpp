#include <iostream>
#include "alpha.cpp"
using namespace std;

int main(){
    cout << "Part 1:" << endl;
    alpha a1(37);
    alpha a2;

    a2 = a1;
    cout << "\na2=";
    a2.display(); //display a2

    alpha a3(a1); //invoke copy constructor
    cout << "\na3=";
    a3.display(); //display a3
    alpha a4 = a1;
    cout << "\na4=";
    a4.display();
    cout << endl;

    return 0;
}
