#include "Package.h"

Package::Package(const string &n, const string &addr, const string &cit, const string &sta, const string &zip, double w, double cpo) {
    name = n;
    address = addr;
    city = cit;
    state = sta;
    zipCode = zip;
    if (w >= 0) weight = w;
    if (cpo >= 0) costPerOunce = cpo;
}

double Package::calculateCost() const {
    return weight * costPerOunce;
}