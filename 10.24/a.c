#include "stdio.h"

int main() {
    int n, sum;
    while (scanf("%d", &n)==1) {
        sum = n;
        while (1) {
            sum += n/3;
            if (n < 3) break;
            n = (n/3 + n%3);
        }
        if (n == 2) sum += 1;
        printf("%d\n", sum);
    }

    return 0;
}