#include "iostream"
#include "date.h"

using namespace std;

Date::Date(int month, int day, int year) : month(month), day(day), year(year) {};

void Date::setMonth(int month) {
    this->month = (month >= 1 && month <= 12) ? month : 1;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setYear(int year) {
    this->year = year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

void Date::displayDate() const {
    cout << getMonth() << "/" << getDay() << "/" << getYear() << "\n";
}