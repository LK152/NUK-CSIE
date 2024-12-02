#include "iostream"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main() {
    {
        Package pkg("a", "address", "kh", "tw", "811", 20, 0.8);

        cout << pkg.calculateCost();
    }

    TwoDayPackage tdp("b", "address", "kh", "tw", "811", 10, 0.9, 15);

    OvernightPackage op("c", "address", "kh", "tw", "811", 25, 0.4, 0.6);

    cout << "\n" << tdp.calculateCost() << "\n" << op.calculateCost() << "\n";

    return 0;
}