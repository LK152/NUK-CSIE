#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(const string& n, const string& addr, const string& cit, const string& sta, const string& zip, double w, double cpo, double afpo)
    : Package(n, addr, cit, sta, zip, w, cpo) {
    additionalFeePerOunce = afpo;
}

double OvernightPackage::calculateCost() const {
    return (getCostPerOunce() + additionalFeePerOunce) * getWeight();
}