#include "iostream"
#include "Date.h"

using namespace std;

int main() {
    Date date;

    int n, year, month, day;
    cin >> n;
    date.nextDay();
    while (n--) {
        cin >> year >> month >> day;

        if (!date.setY(year) || !date.setM(month) || !date.setD(day)) {
            n++;
            cout << "Invalid. Please re-enter.\n";
            continue;
        }

        date.nextDay();
    }

    return 0;
}