#include "stdio.h"
#include "math.h"

int armNum(int n) {
    if (!n) return 0;

    return pow(n%10, 3) + armNum(n/10);
}

int main() {
    int a, b, i;
    scanf("%d %d", &a, &b);

    for (i = a;i<=b;i++) {
        if (armNum(i) == i) printf("%d ", armNum(i));
    }
    return 0;
}