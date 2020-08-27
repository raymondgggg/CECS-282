#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int bin2Dec(const string &binaryString){
    int bin2Dec {0};
    for (int i {0}; i < binaryString.length(); i++){
        bin2Dec += (binaryString[i] - 48) * pow(2,i); // subtracting the char value from 48 brings ASCII to regular int value 
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