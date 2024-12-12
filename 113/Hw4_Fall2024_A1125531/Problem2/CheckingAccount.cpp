#include "CheckingAccount.h"
#include "iostream"

using namespace std;

CheckingAccount::CheckingAccount(double initBalance, double fee)
    : Account(initBalance) {
    feePerTransac = fee;
}

int CheckingAccount::credit(double amount) {
    if (credit(amount))
        debit(feePerTransac);

    return 1;
}

int CheckingAccount::debit(double amount) {
    if (debit(amount)) {
        debit(feePerTransac);
        return 1;
    } else {
        cout << "Debit amount exceeded account balance.\n";
        return 0;
    }
}