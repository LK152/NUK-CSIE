#include "SavingsAccount.h"
#include "iostream"

using namespace std;

SavingsAccount::SavingsAccount(double balance) {
    savingsBalance = balance;
};

double SavingsAccount::annualInterestRate = 0;

void SavingsAccount::calculateMonthlyInterest() {
    savingsBalance += savingsBalance * annualInterestRate / 12;
}

void SavingsAccount::modifyInterestRate(double AIR) {
    annualInterestRate = AIR;
}

void SavingsAccount::printBalance() {
    cout << savingsBalance << "\n";
}