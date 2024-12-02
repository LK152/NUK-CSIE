#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {
    public: 
        explicit OvernightPackage(const string &, const string &, const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0);
        double calculateCost() const;

    private: 
        double additionalFeePerOunce;
};

#endif