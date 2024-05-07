#include "stdio.h"
#include "stdlib.h"

int main() {
    int t, i, j;
    scanf("%d", &t);
    for (i = 0;i<t;i++) {
        int n;
        scanf("%d", &n);
        int* locations = malloc(sizeof(int) * n);
        for (j = 0;j<n;j++) {
            scanf("%d", locations+j);
        }
        int left = 0, right = n-1, cost = 0;
        while(left + 1 < n && locations[left + 1]) left++;
        while(right > 0 && locations[right - 1]) right--;
        cost = (right - left);
        if (cost <= 0) cost = 0;
        printf("%d\n", cost);

        free(locations);
        locations = NULL;
    }

    return 0;
}