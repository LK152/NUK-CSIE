#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    public: 
        explicit Account(double = 0.0);
        int credit(double);
        int debit(double);
        double getBalance() const;

    private: 
        double balance;
};


#endif