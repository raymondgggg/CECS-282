#include <iostream>
#include "Account.h"
using namespace std;

int main(){
    int rate = 0.6;
    Account my_account(10000);
    int initialBalance = my_account.getBalance();
    int final_amount = my_account.getBalance() * 2;
    int months = 0;
    int interest = 6;
    while (my_account.getBalance() < final_amount){
        my_account.addInterest(interest/12);
        cout << my_account.getBalance() << endl;
        months++;
    }
    cout << "It took " << months << "for " << initialBalance << " to double at " << interest << "% annual interest"<< endl;
    cout << "Account Balance: " << my_account.getBalance() << endl;
   
    return 0;
}