#include "stdio.h"

int main() {
    int n, i, sum = 0;
    scanf("%d", &n);
    for (i = 0;i<n;i++) {
        int k;
        scanf("%d", &k);
        if (k<0) sum += -k;
    }
    printf("%d", sum);

    return 0;
}