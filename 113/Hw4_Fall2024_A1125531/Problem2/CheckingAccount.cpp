#include "CheckingAccount.h"

#include "iostream"

using namespace std;

CheckingAccount::CheckingAccount(double initBalance, double fee)
    : Account(initBalance) {
    feePerTransac = fee;
}

int CheckingAccount::credit(double amount) {
    if (Account::credit(amount)) Account::debit(feePerTransac);

    return 1;
}

int CheckingAccount::debit(double amount) {
    if (Account::debit(amount)) {
        Account::debit(feePerTransac);
        return 1;
    } else
        return 0;
}