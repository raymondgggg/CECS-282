#include "functions.h"

int main(){ 
  int *arr {nullptr};
  int size {readData(arr)};

  cout << "Elements: ";
  for (int i {0}; i < size; i++){
      cout << *(arr + i) << " ";
  }
  cout << endl << endl;

  cout << "Ascending Sort: ";
  bubble_sort(arr, size, bSort);
  writeToConsole(arr, size);
  cout << endl;

  cout << "Descending Sort: ";
  bubble_sort(arr, size, descendingBSort);
  writeToConsole(arr, size);
  cout << endl;
  delete arr;
  return 0;
}

