#include "iostream"
#include "iomanip"
#include "Time.h"

using namespace std;

Time::Time(int hr, int min, int sec) {
    setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s) {
    secondsSinceMidnight = h * 60 * 60 + m * 60 + s;
}

int Time::getHour() {
    int hr = secondsSinceMidnight/3600;

    return hr;
}

int Time::getMinute() {
    int min = (secondsSinceMidnight-getHour()*3600)/60;

    return min;
}

int Time::getSecond() {
    int sec = secondsSinceMidnight-getHour()*3600 - getMinute()*60;
    
    return sec;
}

void Time::printUniversal() {
    cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond();
}

void Time::printStandard() {
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM");
}