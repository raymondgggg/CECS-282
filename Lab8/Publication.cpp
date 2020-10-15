#include "Publication.h"
#include <iostream>
using namespace std;
//Define the function getData to get title and price
void Publication::getData(){
    cout << "Title: ";
    getline(cin, this->title);
    cout << "Price: ";
    cin >> this->price;
}

//Define the function putData to get title and price
void Publication::putData(){
    cout << "Title: " << this->title << endl;
    cout << "Price: " << this->price << endl;
}