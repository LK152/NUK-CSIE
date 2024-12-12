#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(const string& n, const string& addr, const string& cit, const string& sta, const string& zip, double w, double cpo, double ff)
    : Package(n, addr, cit, sta, zip, w, cpo) {
    flatFee = ff;
}

double TwoDayPackage::calculateCost() const {
    return getCostPerOunce() * getWeight() + flatFee;
}