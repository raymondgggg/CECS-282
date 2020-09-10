#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <fstream>
#include <iostream>
using namespace std;

int readData(int *&arr)
{
    ifstream indata;
    int num{0};

    indata.open("data.txt");
    indata >> num;
    arr = new int[num];
    int size = num;
    int index{0};

    while (!indata.eof())
    {
        indata >> num;
        *(arr + index) = num;
        index++;
    }
    indata.close();
    return size;
}

void bSort(int *arr, int last)
{
    bool swapped = true;
    int j = 0;
    int tmp;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < last - j; i++)
        {
            if (*(arr + i) > *(arr + i + 1))
            {
                tmp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = tmp;
                swapped = true;
            }
        }
    }
}

void writeToConsole(int *arr, int last)
{
    for (int i{0}; i < last; i++)
    {
        cout << *(arr + i) << " ";
    }
}

void descendingBSort(int *arr, int last)
{
    bool swapped = true;
    int j = 0;
    int tmp;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < last - j; i++)
        {
            if (*(arr + i) < *(arr + i + 1))
            {
                tmp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = tmp;
                swapped = true;
            }
        }
    }
}

void bubble_sort(int *arr, int size, void (*sortFunct)(int *arr, int))
{
    sortFunct(arr, size);
}

#endif //_FUNCTIONS_H_