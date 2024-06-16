#include "stdio.h"

int main() {
    int n, a, f, i, j, k, l;
    scanf("%d\n", &n);
    for (i = 0;i<n;i++) {
        scanf("%d %d", &a, &f);
        for (j = 0;j<f;j++) {
            for (k = 1;k<=a;k++) {
                for (l = 0;l<k;l++) {
                    putchar(k + 48);
                }
                printf("\n");
            }
            for (k = a-1;k>0;k--) {
                for (l = 0;l<k;l++) {
                    putchar(k + 48);
                }
                printf("\n");
            }
            if (j < f-1) printf("\n");
        }
        if (i < n-1) printf("\n");
    }

    return 0;
}