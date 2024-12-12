#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
    public:
        explicit CheckingAccount(double, double);
        int credit(double);
        int debit(double);

    private:
        double feePerTransac;
};

#endif