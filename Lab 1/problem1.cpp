#include <iostream>
#include <string>

using namespace std;

int main(){
    string usrInput;

    cout << "Please enter a number: ";
    cin >> usrInput;
    cout << endl;

    int oddSum {};
    for(char c : usrInput){
        if((c-48) % 2 != 0){//48 ASCII value that will bring the char value to the actual number 
            oddSum += (c-48); 
        }
    }

    cout << "The sum of the odd numbers in " << usrInput << " is: " << oddSum << endl;
    return 0;
}