#ifndef TIME_H
#define TIME_H

class Time {
    public: 
        Time(int = 0, int = 0, int = 0);

        void setTime(int, int, int);

        int getHour();
        int getMinute();
        int getSecond();

        void printUniversal();
        void printStandard();

    private:
        int secondsSinceMidnight;
};

#endif