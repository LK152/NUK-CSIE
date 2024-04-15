#include "stdio.h"

int main() {
    int n, m, i;

    scanf("%d %d", &n, &m);

    if (m > 2*(n+1) || n > m+1) {
        printf("-1");
        return 0;
    }

    if (n-m == 1) {
        putchar('0');
        for (i = 0;i<m;i++) {
            putchar('1');
            putchar('0');
        }

        return 0;
    }

    while (n && m) {
        if (m < 2*n) {
            putchar('1');
            putchar('0');
            m--;
            n--;
        } else {
            putchar('1');
            putchar('1');
            putchar('0');
            m -= 2;
            n--;
        }
    }

    for (i = 0;i<m;i++) {
        putchar('1');
    }


    return 0;
}