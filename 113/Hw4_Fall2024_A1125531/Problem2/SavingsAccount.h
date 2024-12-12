#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
    public: 
        explicit SavingsAccount(double, double);
        double calculateInterest() const;

    private: 
        double interestRate;

};

#endif