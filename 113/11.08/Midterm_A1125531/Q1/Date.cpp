#include "iostream"
#include "Date.h"

using namespace std;

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {};

bool Date::setY(int y) {
    if (y >= 1) {
        year = y;
        return 1;
    }

    return 0;
}

bool Date::setM(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
        return 1;
    }

    return 0;
}

bool Date::setD(int d) {
    switch (month) {
        case 2: 
            if (isLeap(year)) {
                maxDay = 29;
                if (d <= 29 && d >= 1) {
                    day = d;
                    return 1;
                }
            } else if (d <= 28 && d >= 1) {
                maxDay = 28;
                day = d;
                return 1;
            }
            return 0;
            break;

        default: 
            if (month <= 7) {
                if (month % 2) {
                    maxDay = 31;
                    if (d <= 31 && d >= 1) {
                        day = d;
                        return 1;
                    }
                } else if (d <= 30 && d >= 1) {
                    maxDay = 30;
                    day = d;
                    return 1;
                }
            }
            else {
                if (month % 2) {
                    maxDay = 31;
                    if (d <= 30 && d >= 1) {
                        day = d;
                        return 1;
                    }
                } else if (d <= 31 && d >= 1) {
                    maxDay = 30;
                    day = d;
                    return 1;
                }
            }
            return 0;
            break;
    }
}

void Date::nextDay() {
    if (++day > maxDay) {
        day = 1;
        if (++month > 12) {
            month = 1;
            year++;
        }
    }

    cout << year << "/" << month << "/" << day << "\n";
}

bool Date::isLeap(int y) const {
    if (!(y % 4) && y % 100) return 1;
    if (!(y % 400)) return 1;

    return 0;
}