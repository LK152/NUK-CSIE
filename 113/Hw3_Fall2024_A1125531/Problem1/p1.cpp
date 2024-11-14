#include "iostream"
#include "Date.h"

using namespace std;

int main() {
    int y, m, d;

    while (1) {
        cout << "Enter in mm dd yyyy\n";
        cin >> m >> d >> y;

        Date date(m, d, y);

        date.print();
        date.nextDay();
        date.print();
    }


    return 0;
}