#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "iostream"

using namespace std;

int main() {
    SavingsAccount savingsAcc(2500.0, 8.0);
    CheckingAccount checkingAcc(3000.0, 15.0);

    cout << "Savings Account Balance: " << savingsAcc.getBalance()
         << "\nCredit 1000: " << savingsAcc.credit(1000)
         << "\nDebit 10000: " << savingsAcc.debit(10000)
         << "\nDebit 1000:" << savingsAcc.debit(1000)
         << "\nInterest: " << savingsAcc.calculateInterest()
         << "\nAfter Interest: " << savingsAcc.credit(savingsAcc.calculateInterest());

    cout << "\n\nChecking Account: " << checkingAcc.getBalance()
         << "\nCredit 1000: " << checkingAcc.credit(1000)
         << "\n Debit 10000: " << checkingAcc.debit(10000)
         << "\n Debit 1000: " << checkingAcc.debit(1000);

    return 0;
}