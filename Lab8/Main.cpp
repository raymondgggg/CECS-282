// Raymond Guevara Lozano 
// CECS 282 Lab 8
#include "Sale.cpp"
#include "Publication.cpp"
#include "Book.cpp"
#include "Digital.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Book book;
    Digital digital;
    book.getData();
    book.putData();
    cout << endl << endl;
    cin.ignore();
    digital.getData();
    digital.putData();
    cout << endl;
    return 0;
}