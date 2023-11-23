#include "stdio.h"
#include "math.h"

int sumDigits(int n) {
    int sum;
    
    for (sum = 0;n;sum += n%10, n /= 10);

    if (floor(log10(sum)) + 1 >= 2) return sumDigits(sum);

    return sum;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);

        if (!n) return 0;

        printf("%d\n", sumDigits(n));
    }

    return 0;
}