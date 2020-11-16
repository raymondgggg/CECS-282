// listplus.cpp
// demonstrates reverse(), merge(), and unique()
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){

    //Create 2 lists called list1 and list2. Store integer numbers.
    list<int> list1;
    list<int> list2;
    
    int arr1[] = {40, 30, 20, 10};

    int arr2[] = {15, 20, 25, 30, 35};

    //Determine the array size of arr1 and arr2
    int size1 = sizeof(arr1) / sizeof(arr1[1]);
    int size2 = sizeof(arr2) / sizeof(arr2[1]);
    //Push elements of array arr1 into list1
    for (int num : arr1){
        list1.push_back(num);
    }
    //Push elements of array arr2 into list2
    for (int num : arr2){
        list2.push_back(num);
    }
    // reverse list1: 10 20 30 40
    reverse(list1.begin(), list1.end());
    // merge list2 into list1
    list1.merge(list2);
    // remove duplicate 20 and 30 from list 1
    list1.unique();
    //Diplay the content of list1 using iterator
    cout << "List 1: ";
    for (list<int>::iterator i = list1.begin(); i != list1.end(); ++i){
        cout << *i << " ";
    }
    cout << endl;
    //Display the list1 in reverse
    reverse(list1.begin(), list1.end());
    cout << "List 1 reverse: ";
    for (auto i : list1){
        cout << i << " ";
    }
    cout << endl;
    //Find 25 in the list. If it's found, display "Found 25";otherwise, display "Not found 25"
    // list1.remove(25);
    int count {0};
    for (auto i : list1){
        if (i == 25){
            cout << "Found 25" << endl;
            break;
        }
        if (count == list1.size()-1 && i != 25)
            cout << "Not found 25" << endl;
        count++;
    }
    return 0;
}