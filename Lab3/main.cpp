#include <iostream>
#include <fstream>
using namespace std;

int readData(int *&arr);
void bSort(int *arr, int last);
void ascendingSort(int *&arr);
void descendingSort(int *&arr);
void bubble_sort(int *array, int size, void(*funct)(int));

int funct(int *&arr)
{
    arr = new int[9];
    *arr = 1;
    *(arr + 1) = 3;
    return 0;
}

int main(){ 
  int *arr {nullptr};
  funct(arr);
  cout << *arr << endl;
  cout << *(arr +1) << endl;
}


