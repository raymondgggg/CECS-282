#include <iostream>
#include <string>
using namespace std;
void transform(char *raw, char *&testStr);
bool testPalindrome(char *str);

int main(){
    string usrInput;
    cout << "Enter String: ";
    getline(cin, usrInput);

    char *raw = &usrInput[0];
    char *testStr;
    transform(raw, testStr);

    if (testPalindrome(testStr)){
        cout << "The string entered is a palindrome." << endl;
    }
    else{
        cout << "The string entered is not a palindrome." << endl;
    }
    
    delete [] testStr;
    return 0;
}

void transform(char *raw, char *&testStr){
    int i {0};
    int testStrLen {0};
    while (raw[i] != '\0'){
        if(isalpha(raw[i]) || isdigit(raw[i])){
            ++testStrLen;
        }
        ++i;
    }
    testStr = new char[testStrLen+1];
    int j {0};
    int k {0};
    while (raw[j] != '\0'){
        if (isalpha(raw[j]) || isdigit(raw[j])){
            testStr[k] = toupper(raw[j]);
            ++k;
        }
        ++j;
    }
    ++k;
    testStr[k] = '\0'; //terminating null char
}

bool testPalindrome(char *str){
    int pointerLen {0};
    while (str[pointerLen] != '\0'){
        ++pointerLen;
    }
    
    // check to see if chars are the same forward and backwards
    for (int i {0}; i < pointerLen; ++i){
        if (str[i] != str[pointerLen - (i+1)]){
            return false;// false if linearly compared elements are not the same
        }
    }
    return true;// value returned if arrays are both the same
}