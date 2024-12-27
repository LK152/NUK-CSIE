#include <iostream>
#include <stdexcept>

using namespace std;

double divide(double numer, double denom) {
    if (denom == 0) {
        throw invalid_argument("���Ƥ��ର�s");
    }
    return numer / denom;
}

int main() {
    double numer, denom;
    bool retry = true;

    while (retry) {
        try {
            cout << "�п�J�Q����: ";
            cin >> numer;
            cout << "�п�J����: ";
            cin >> denom;

            double result = divide(numer, denom);
            cout << "���G: " << result << std::endl;
            retry = false; 
        } catch (const invalid_argument& e) {
            cerr << "���~: " << e.what() << endl;
            cout << "�Э��s���տ�J���Ī��Ʀr�C" << endl;
        }
    }

    return 0;
}