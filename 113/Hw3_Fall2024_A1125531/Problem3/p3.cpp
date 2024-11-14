#include "iostream"
#include "Time.h"

using namespace std;

int main() {
    int hr, min, sec;
    Time time;
    
    while (1) {
        cin >> hr >> min >> sec;
        time.setTime(hr, min, sec);

        time.printUniversal();
        cout << "\n";
        time.printStandard();
        cout << "\n";
    }
    

    return 0;
}