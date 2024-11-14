#include "iostream"
#include "SavingsAccount.h"

using namespace std;

int main() {
    SavingsAccount saver1(2000.00), saver2(3000.00);

    saver1.modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.printBalance();
    saver2.printBalance();

    saver2.modifyInterestRate(0.04);
    
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.printBalance();
    saver2.printBalance();
}