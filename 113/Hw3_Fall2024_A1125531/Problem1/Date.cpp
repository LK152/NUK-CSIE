#include "iostream"
#include "Date.h"

using namespace std;

Date::Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

void Date::print() {
    cout << month << "/" << day << "/" << year << "\n";
}

void Date::nextDay() {
    switch (month) {
        case 2: 
            if (isLeap(year)) {
                if (++day > 29) {
                    day = 1;
                    ++month;
                }
            } else {
                if (++day > 28) {
                    day = 1;
                    ++month;
                }
            }
            break;

        case 12:
            if (++day > 31) {
                day = 1;
                month = 1;
                ++year;
            }
            break;

        default: 
            if (month <= 7) {
                if (month%2) {
                    if (++day > 31) {
                        day = 1;
                        ++month;
                    }
                } else {
                    if (++day > 30) {
                        day = 1;
                        ++month;
                    }
                }
            } else {
                if (!(month%2)) {
                    if (++day > 31) {
                        day = 1;
                        ++month;
                    }
                } else {
                    if (++day > 30) {
                        day = 1;
                        ++month;
                    }
                }
            }
            break;
    }
}

bool Date::isLeap(int y) {
    if (!(y%400)) return 1;
    if (!(y%4) && y%100) return 1;

    return 0;
}