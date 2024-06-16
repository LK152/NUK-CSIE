#include "stdio.h"

int main() {
    int t, n, walls[100], i, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int hi = 0, lo = 0;
        scanf("%d", &n);
        for (i = 0;i<n;i++) {
            scanf("%d", &walls[i]);
        }
        for (i = 1;i<n;i++) {
            if (walls[i] > walls[i-1]) hi++;
            if (walls[i] < walls[i-1]) lo++;
        }

        printf("Case %d: %d %d\n", ca++, hi, lo);
    }


    return 0;
}