#include "SavingsAccount.h"
#include "iostream"

using namespace std;

SavingsAccount::SavingsAccount(double initBalance, double initRate)
    : Account(initBalance) {
    interestRate = initRate / 100;
}

double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}