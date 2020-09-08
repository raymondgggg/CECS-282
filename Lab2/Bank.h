#ifndef _BANK_H_
#define _BANK_H_
#include "Account.h"
#include <string>

class Bank{
    Account checkings;
    Account savings;

    public:
        Bank()
            : Bank {0,0}{ //if no arguments are given for constructor, initialize empty savings and checking account

        }

        Bank(double checking_amount, double savings_amount)
            : checkings {Account(checking_amount)}, savings {Account(savings_amount)} {

        }

        void deposit(double amount, std::string account){
            if(account.compare("s") == 0 || account.compare("S") == 0){
                savings.deposit(amount);
            }
            else if(account.compare("C") == 0 || account.compare("c") == 0){
                checkings.deposit(amount);  
            }
        }

        void withdraw(double amount, std::string account){
            if (account.compare("s") == 0 || account.compare("S") == 0){
                savings.withdraw(amount);
            }
            else if (account.compare("C") == 0 || account.compare("c") == 0){
                checkings.withdraw(amount);
            }
        }

        void transfer(double amount, std::string account){
            if (account.compare("s") == 0 || account.compare("S") == 0){
                if (savings.withdraw(amount)){
                    std::cout << "$" << amount << " transfered to " << "checking" << std::endl;
                    checkings.deposit(amount);
                }
                else{
                    std::cout << "Cannot transfer money, penalized $5" << std::endl;
                }
            }
            else if (account.compare("C") == 0 || account.compare("c") == 0){
                if (checkings.withdraw(amount)){
                    std::cout << "$" << amount << " transfered to " << "savings" << std::endl;
                    savings.deposit(amount);
                }
                else{
                    std::cout << "Cannot transfer money, penalized $5" << std::endl;
                }
            }
        }

        void print_balances(){
            std::cout<< "Checkings: " << checkings.getBalance() << std::endl;
            std::cout<< "Savings: " << savings.getBalance() << std::endl;
        }
};
#endif //_BANK_H_