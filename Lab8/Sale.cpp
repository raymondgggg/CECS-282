#include "Sale.h"
//Define the function getData to input sales for three months
void Sale::getData(){
    cout << "Enter sales for last 3 months" << endl;
    for (int i = 0; i < 3; i++){
        cout << "Enter data for month " << i + 1 << ": ";
        cin >> this->saleArray[i];
    }
}

//Define the function putData to display three months of sales
void Sale::putData(){
    cout << "Data for the last 3 months" << endl;
    for (int i = 0; i < 3; i++){
        cout << "Month " << i + 1 << ": " << this->saleArray[i] << endl;
    }
}