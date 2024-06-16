#include "stdio.h"
#include "math.h"

void primes(int* prime) {
    int i, j;
    for (i = 0;i<1300000;i++) {
        prime[i] = 0;
    }
    prime[0] = 1;
    prime[1] = 1;
    for (i = 2; i < sqrt(1300000) ; i++) if (prime[i]==0) for (j = i + i ; j < 1300000 ; j += i) prime[j] = 1;
}

int main() {
    int prime[1300000], n, i, j;
    primes(prime);

    while (1) {
        scanf("%d", &n);
        if (!n) return 0;

        if (!prime[n]) printf("0\n");
        else {
            for(i = n ; prime[i] != 0 ; i++);
            for(j = n ; prime[j] != 0 ; j--);
            printf("%d\n", i-j);
        }
    }
}