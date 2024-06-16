#include "stdio.h"

int main() {
    int n, k;

    while (scanf("%d %d", &n, &k) != EOF) {
        int out;
        for (out = n;n>=k;out += n/k, n = n/k + n%k);

        printf("%d\n", out);
    }

    return 0;
}