#include <iostream>
#include <fstream>

using namespace std;

void inputRainfall(int rainFall[], int size);

int main(){
    int arr[12] {0};
    int size {12};

    inputRainfall(arr,size);
    
    return 0;
}


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