#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account{
    int balance; 

    public:
        Account() // when object created with no constructor
            : Account {0} {
            
        }

        Account(int money) 
            : balance {money} {
        }

        void deposit(int money){
            balance += money;
        }

        void withdraw(int money){
            if(money > balance){
                balance -= 5;
            }
            else{
                balance -= money;
            }
        }

        int getBalance(){
            return balance;
        }

        void addInterest(int rate){ //annual interest rate 
            balance *= (1 + rate/100);
        }
};

#endif //_ACCOUNT_H_