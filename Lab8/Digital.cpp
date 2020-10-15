#include "Digital.h"
#include <iostream>

//Define the functions getData to input publication, storage and three months of sales
void Digital::getData(){
    Publication::getData();
    Sale::getData();
    cout << "Enter the amount of storage the book takes up (MB): ";
    cin >> this->storage;
}

//Define the function putData to display the publication, storage and three months of sales
void Digital::putData(){
    Publication::putData();
    Sale::putData();
    cout << "Storage of book (MB): " << this->storage << endl;
}