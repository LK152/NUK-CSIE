#include "Account.h"
#include "iostream"

using namespace std;

Account::Account(double initBalance) {
    if (initBalance >= 0.0)
        balance = initBalance;
    else {
        balance = 0.0;
        cout << "Invalid initial balance\n";
    }
}

int Account::credit(double amount) {
    balance += amount;
    return 1;
}

int Account::debit(double amount) {
    if (amount > balance) {
        cout << "Debit amount exceeded account balance.\n";

        return 0;
    } else {
        balance -= amount;
        return 1;
    }
}

double Account::getBalance() const {
    return balance;
}