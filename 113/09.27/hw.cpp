#include "iostream"

using namespace std;

void swap1(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void swap2(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    int a = 1, b = 2;

    cout << "a=" << a << ", b=" << b << "\n";
    swap1(&a, &b);
    cout << "a=" << a << ", b=" << b << "\n";
    swap2(a, b);
    cout << "a=" << a << ", b=" << b << "\n";

    return 0;
}