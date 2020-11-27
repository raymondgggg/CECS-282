#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template <class T>
bool testPalindrome(vector<T> input){
    for (int i {0}; i < input.size(); ++i){
        if (input[i] != input[input.size() - (i+1)]){
            return false;
        }
    }
    return true;
}

template <class T>
void test(vector<T> input){
    for (auto i : input)
        cout << i << " ";
    if (testPalindrome(input))
        cout << "is a palindrome" << endl;
    else
        cout << "is not a palindrome" << endl;
}

int main(){
    vector<int> ints;
    vector<char> chars;

    string str;
    cout << "Enter single-digit separated by space:" << endl;
    getline(cin, str);
    istringstream my_stream(str);
    int n;
    while (my_stream >> n){
        ints.push_back(n);
    }
    test(ints);

    cout << "Enter a string without spaces:" << endl;
    getline(cin, str);
    for (auto c: str)
        chars.push_back(c);
    test(chars);

    return 0;
}