#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include "iostream"

using namespace std;

int main() {
    TwoDayPackage tdp("b", "address", "kh", "tw", "811", 10, 0.9, 15);

    OvernightPackage op("c", "address", "kh", "tw", "811", 25, 0.4, 0.6);

    cout << tdp.calculateCost() << "\n" << op.calculateCost() << "\n";

    return 0;
}