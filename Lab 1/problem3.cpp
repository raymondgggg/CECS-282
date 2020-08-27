#include <iostream>
#include <fstream>

using namespace std;

void inputRainfall(int rainFall[], int size){
    ifstream file ("rainfall.txt");

    int input;
    int index {0};
    while(file >> input){
        if (index < size){
            rainFall[index] = input;
            index ++;
        }
        else{
            break;
        }
    }
}

int main(){
    int arr[12] {0};
    int size {12};

    cout << "Before inserting values: ";
    for(int value : arr){
        cout << value << " ";
    }

    inputRainfall(arr,size);
 
    cout << endl;

    cout << "afterinserting values: ";
    for(int value : arr){
        cout << value << " ";
    }
    return 0;
}