#include "stdio.h"
#include "math.h"

int main() {
    unsigned long long n;
    while (1) {
        scanf("%llu", &n);
        if (!n) return 0;

        printf("%llu\n", (n*n*n*n*n*n+12*n*n*n+3*n*n*n*n+8*n*n)/24);
    }

    return 0;
}