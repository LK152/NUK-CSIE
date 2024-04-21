#include "stdio.h"

int main() {
    int n;
    while (1) {
        int i, j, k = 1;
        scanf("%d", &n);
        if (!n) return 0;
        if (n%2 || n == 2) {
            printf("Impossible\n");
            continue;
        }
        printf("%d\n", n/2 + n);
        for (i = 1;i<n;i++) {
            for (j = k;j<n;j++) {
                printf("%d %d\n", i, j+1);
            }
            k++;
        }
    }


    return 0;
}