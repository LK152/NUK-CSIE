#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
    public: 
        explicit SavingsAccount(double balance);
        void calculateMonthlyInterest();
        void modifyInterestRate(double AIR);
        void printBalance();

    private: 
        double savingsBalance;
        static double annualInterestRate;
};


#endif