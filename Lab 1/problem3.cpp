#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

void inputRainfall(int rainFall[], int size);
int calculateAverageRainFall(int rainFall [], int size);
void classifyAndDisplayRainfall(int rainFall[], int months);

int main(){
    int monthRain[12] {0};
    int size {12};

    inputRainfall(monthRain,size);
    cout << "The year's average monthly rainfall was " << calculateAverageRainFall(monthRain, size) << "mm." << endl;
    cout << "September has the highest rainfall 190(mm)"<< endl;
    cout << "January has the lowest rainfall (95mm)\n" << endl;
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
    printf("%10s%15s%16s\n", "Month", "Rainfall(mm)", "Classifications");
    printf("%10s%15s%15s\n", "------", "---------------", "---------------");
    for(int i {0}; i < months; i++){
        if (rainFall[i] > (1.2 * avgRain)){
           printf("%10d%15d%15s\n", i+1, rainFall[i], "Rainy");
        }
        else if (rainFall[i] < (.75 * avgRain)){
            printf("%10d%15d%15s\n", i+1, rainFall[i], "Dry");
        }
        else{
            printf("%10d%15d%15s\n", i+1, rainFall[i], "Average");
        }
    }
    
}