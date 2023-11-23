#include "stdio.h"

int gcd(int n1, int n2) {
    if (n2) return gcd(n2, n1%n2);
    else return n1;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (!n) return 0;

        int g = 0, i, j;
        for (i = 1;i<n;i++) {
            for (j = i+1;j<=n;j++) {
                g += gcd(i, j);
            }
        }

        printf("%d\n", g);
    }

    return 0;
}