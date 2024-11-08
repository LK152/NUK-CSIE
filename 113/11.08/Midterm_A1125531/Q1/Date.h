class Date {
    private: 
        int day, month, year, maxDay;

    public: 
        Date(int day = 1, int month = 1, int year = 2000);

        bool setY(int);
        bool setM(int);
        bool setD(int);
        void nextDay();

        bool isLeap(int) const;
};