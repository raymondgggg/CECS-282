#include <iostream>
#include "alpha.cpp"
#include "pointerDataClass.cpp"
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
    cout << endl << endl;

    cout << "Part 2 and 3: " << endl;
    pointerDataClass list1(10);
    list1.insertAt(0, 50);
    list1.insertAt(4, 30);
    list1.insertAt(8, 60);
    cout << "List1: " << endl;
    list1.displayData();
    cout << "List 2: " << endl;
    pointerDataClass list2(list1);
    list2.displayData();
    list1.insertAt(4, 100);
    cout << "List1: (after insert 100 at indext 4) " << endl;
    list1.displayData();
    cout << "List 2: " << endl;
    list2.displayData();
    cout << endl;
    return 0;
}