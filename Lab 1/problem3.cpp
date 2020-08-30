#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <bits/stdc++.h> 

using namespace std;

void inputRainfall(int rainFall[], int size);
int calculateAverageRainFall(int rainFall [], int size);
void classifyAndDisplayRainfall(int rainFall[], int months);

int main(){
    int monthRain[12] {0};
    int size {12};

    inputRainfall(monthRain,size);
    cout << "The year's average monthly rainfall was " << calculateAverageRainFall(monthRain, size) << "mm." << endl;
    classifyAndDisplayRainfall(monthRain, size);

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
    }
}

int calculateAverageRainFall(int rainFall[], int size){
    double sum {0};

    for (int i {0}; i < size; i++){
        sum += rainFall[i];
    }

    double avgRain = sum / size;
    return ceil(avgRain);
}

void classifyAndDisplayRainfall(int rainFall[], int months){
    int avgRain = calculateAverageRainFall(rainFall, months);
    string monthsArr[12] = {"January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};
    int highestRain {rainFall[0]};
    int highestRainIndex {0};
    int lowestRain{rainFall[0]};
    int lowestRainIndex {0};
    for (int i {0}; i < months; i++){
        if (rainFall[i] > highestRain){
            highestRain = rainFall[i];
            highestRainIndex = i;
        }
        if (rainFall[i] < lowestRain){
            lowestRain = rainFall[i];
            lowestRainIndex = i;
        }
    }

    cout << monthsArr[highestRainIndex] << " has the highest rainfall " << "(" << rainFall[highestRainIndex] << "mm)." << endl;
    cout << monthsArr[lowestRainIndex] << " has the lowest rainfall " << "(" << rainFall[lowestRainIndex] << "mm)." << endl;
    cout << endl;
    printf("%-10s%-15s%-16s\n", "Month", "Rainfall(mm)", "Classifications");
    printf("%-10s%8s%8s\n", "------ ", "------------  ", "----------------");

    for(int i {0}; i < months; i++){
        if (rainFall[i] > (1.2 * avgRain)){
           printf("%4d%13d%17s\n", i+1, rainFall[i], "Rainy");
        }
        else if (rainFall[i] < (.75 * avgRain)){
            printf("%4d%13d%17s\n", i+1, rainFall[i], "Dry");
        }
        else{
            printf("%4d%13d%17s\n", i+1, rainFall[i], "Average");
        }
    } 
}
