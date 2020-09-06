#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account{
    double balance; 

    public:
        Account() // when object created with no constructor
            : Account {0} {
        }

        Account(double money) 
            : balance {money} {
        }

        void deposit(double money){
             balance += money;
        }

        bool withdraw(double money){
            if(money > balance){
                 balance -= 5;
                 return false;
            }
            else{
                 balance -= money;
                 return true;   
            }
        }

        double getBalance(){
            return balance;
        }

        void addInterest(double rate){ //annual interest rate 
            balance *= (1 + rate/100);
        }
};

#endif //_ACCOUNT_H_