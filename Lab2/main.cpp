#include <iostream>
#include <cmath>
#include "Account.h"
#include "Bank.h"
using namespace std;

int main(){
    Bank my_bank;
    cout << "Inital bank balances: \n";
    my_bank.print_balances(); /* set up empty accounts */
    cout<<endl;

    cout << "Adding some money to accounts: \n";
    my_bank.deposit(1000, "S"); /* deposit $1000 to savings */
    my_bank.deposit(2000, "C"); /* deposit $2000 to checking */
    my_bank.print_balances();
    cout<<endl;

    cout << "Taking out $1500 from checking,and moving $200 from";
    cout << " savings to checking.\n";
    my_bank.withdraw(1500, "C"); /* withdraw $1500 from checking */
    my_bank.transfer(200, "S");  /* transfer $200 from savings */
    my_bank.print_balances();
    cout << endl;

    cout << "Trying to transfer $900 from Checking.\n";
    my_bank.transfer(900, "C");
    my_bank.print_balances();
    cout << endl;

    cout << "Trying to transfer $900 from Savings.\n";
    my_bank.transfer(900, "S");
    my_bank.print_balances();

    return 0;
}