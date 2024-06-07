#include "stdio.h"
#include "math.h"

unsigned int reverse(unsigned int n) {
    unsigned int rev = 0;

    while (n) {
        rev *= 10;
        rev += n%10;
        n /= 10;
    }

    return rev;
}

int main() {
    int n, it;
    unsigned int p;
    scanf("%d", &n);
    while (n--) {
        it = 0;
        scanf("%u", &p);

        do {
            p += reverse(p);
            it++;
        } while (p != reverse(p));

        printf("%d %u\n", it, p);
    }

    return 0;
}