// Raymond Guevara Lozano
// Brent Nishioka
// CECS 282-sec 07

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int bin2Dec(const string &binaryString){ //& means that we are passing by reference 
    int bin2Dec {0};
    int POWERS_OF_TWO[binaryString.length()] = {0};
    POWERS_OF_TWO[0] = 1;
    for (int i {1}; i<=binaryString.length();i++){
        int base {2};
        int result {1};
        for (int j {0}; j < i; j++){
            result *= base;
        }
        POWERS_OF_TWO[i] = result;
    }

    int size {0};
    while(binaryString[size]){
        size++;
    }

    int powerIndex {0};
    for (int i {size}; i > 0 ; i--){
        bin2Dec += (binaryString[i-1] - 48) * POWERS_OF_TWO[powerIndex];
        powerIndex++;                                                     // subtracting the char value from 48 brings ASCII to regular int value 
    }
    return bin2Dec;
}

int main(){
    string binaryNum;
    cout << "Please enter a binary number: ";
    cin >> binaryNum;
    cout << endl;
    cout << binaryNum << " to decimal is: " << bin2Dec(binaryNum) << endl;
    return 0;
}