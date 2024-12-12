#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "iostream"

using namespace std;

int main() {
    SavingsAccount savingsAcc(2500.0, 8.0);
    CheckingAccount checkingAcc(3000.0, 15.0);

    cout << "Savings Account Balance: " << savingsAcc.getBalance() << "\n";
    savingsAcc.credit(1000);
    cout << "Credit 1000: " << savingsAcc.getBalance() << "\n";
    savingsAcc.debit(10000);
    cout << "Debit 10000: " << savingsAcc.getBalance();
    savingsAcc.debit(1000);
    cout << "\nDebit 1000:" << savingsAcc.getBalance();
    cout << "\nInterest: " << savingsAcc.calculateInterest();
    savingsAcc.credit(savingsAcc.calculateInterest());
    cout << "\nAfter Interest: " << savingsAcc.getBalance();

    cout << "\n\nChecking Account Balance: " << checkingAcc.getBalance();
    checkingAcc.credit(1000);
    cout << "\nCredit 1000: " << checkingAcc.getBalance() << "\n";
    checkingAcc.debit(10000);
    cout << "Debit 10000: " << checkingAcc.getBalance();
    checkingAcc.debit(1000);
    cout << "\nDebit 1000: " << checkingAcc.getBalance();

    return 0;
}