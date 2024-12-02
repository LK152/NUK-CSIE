#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
    public: 
        explicit TwoDayPackage(const string &, const string &, const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0);
        double calculateCost() const;

    private: 
        double flatFee;
};

#endif