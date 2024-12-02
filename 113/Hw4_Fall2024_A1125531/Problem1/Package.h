#ifndef PACKAGE_H
#define PACKAGE_H

#include "string"

using namespace std;

class Package {
    public: 
        explicit Package(const string &, const string &, const string &, const string &, const string &, double = 0.0, double = 0.0);
        double calculateCost() const;

    protected: 
        string name, address, city, state, zipCode;
        double weight, costPerOunce;
};

#endif