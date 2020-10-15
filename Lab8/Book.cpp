#include "Publication.h"
#include "Sale.h"
#include "Book.h"

//Define the function getData to get the publication, sales, and page count
void Book::getData(){
    Publication::getData();
    Sale::getData();
    cout << "Enter number of pages in book: ";
    cin >> this->pageCount;
}

//Define the function putData to display the publication, sales, and page count
void Book::putData(){
    Publication::putData();
    Sale::putData();
    cout << "Pages in book: " << this->pageCount;
}