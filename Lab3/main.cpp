#include <iostream>
#include <fstream>
using namespace std;

int readData(int *&arr);
void bSort(int *arr, int last);
void writeToConsole(int *arr, int last);
void descendingSort(int *arr, int last);
void bubble_sort(int *array, int size, void(*funct)(int *arr, int));

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
  bubble_sort(arr, size, descendingSort);
  writeToConsole(arr, size);
  cout << endl;
}

int readData(int *&arr){
    ifstream indata;
    int num{0};

    indata.open("data.txt");
    indata >> num;
    arr = new int[num];
    int size = num;
    int index {0};
    
    while (!indata.eof()){
        indata >> num;
        *(arr + index) = num;
        index++;
    }
    indata.close();
    return size;
}

void bSort(int *arr, int last){
    bool swapped = true;
    int j = 0;
    int tmp;

    while (swapped){
        swapped = false;
        j++;
        for (int i = 0; i < last - j; i++){
            if (*(arr + i) > *(arr + i + 1)){
                tmp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = tmp;
                swapped = true;
            }
        }
    }
}

void writeToConsole(int *arr, int last){
    for (int i{0}; i < last; i++){
        cout << *(arr + i) << " ";
    }
}

void descendingSort(int *arr, int last){
    bool swapped = true;
    int j = 0;
    int tmp;

    while (swapped){
        swapped = false;
        j++;
        for (int i = 0; i < last - j; i++){
            if (*(arr + i) < *(arr + i + 1)){
                tmp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = tmp;
                swapped = true;
            }
        }
    }
}

void bubble_sort(int *arr, int size, void (*sortFunct)(int *arr, int)){
    sortFunct(arr, size);
}