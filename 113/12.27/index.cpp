#include <iostream>
#include <stdexcept>

using namespace std;

double divide(double numer, double denom) {
    if (denom == 0) {
        throw invalid_argument("除數不能為零");
    }
    return numer / denom;
}

int main() {
    double numer, denom;
    bool retry = true;

    while (retry) {
        try {
            cout << "請輸入被除數: ";
            cin >> numer;
            cout << "請輸入除數: ";
            cin >> denom;

            double result = divide(numer, denom);
            cout << "結果: " << result << std::endl;
            retry = false; 
        } catch (const invalid_argument& e) {
            cerr << "錯誤: " << e.what() << endl;
            cout << "請重新嘗試輸入有效的數字。" << endl;
        }
    }

    return 0;
}