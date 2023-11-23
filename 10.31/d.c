#include "stdio.h"

int sum(int n) {
    int sum = 0;
    while (n>0) {
        sum += n%10;
        n /= 10;
    }

    return sum;
}

int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (!a && !b) break;
        int op = (sum(a) + sum(b) - sum(a+b)) / 9;
        if (op == 1) printf("1 carry operation.\n");
        else if (op) printf("%d carry operations.\n", op);
        else printf("No carry operation.\n");
    }

    return 0;
}