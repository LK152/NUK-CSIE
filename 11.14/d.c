#include "stdio.h"
#include "math.h"

int isPrime(int n) {
    int i;
    if (n<=1) return 0;
    for (i = 2;i<=sqrt(n);i++) {
        if (!(n%i)) return 0;
    }
    return 1;
}

int main() {
    int n, primes[1000001];
    long long i;

    for (i = 2; i < 1000001; ++i) {
		if (isPrime(i)) primes[i] = i;
	} 

    while (1) {
        scanf("%d", &n);
        if (!n) return 0;
        int count = 0, k;
        for (k = 2; k <= n / 2; ++k) {
            if(isPrime(n-primes[k])){
                count++;
            }
        }

        printf("%d\n", count);
    }


    return 0;
}