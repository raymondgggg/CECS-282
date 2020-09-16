#include <iostream>
#include "Person.h"
using namespace std;

void bSort(Person**, int n, bool s);


int main(){
    int size = 5;
    int numbers[size] = {1,2,3,4,5};
    int *ptr = &numbers[0];
    int **ptr2 = &ptr;
    cout << ptr2 << endl;
    cout << ptr2 + 1 << endl;
    cout << ptr << endl;
    cout << *ptr2 << endl;
    cout << *(ptr + 1) << endl;
    cout << *(*(ptr2) + 1) << endl;
   
    return 0;
}