#include "stdio.h"

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0;i<n;i++) {
        int k, j;
        scanf("%d", &k);
        int input[k];
        for (j = 0;j<k;j++) {
            scanf("%d", &input[j]);
        }
        printf("%s\n", input[0] == 1 ? "YES" : "NO");
    }

    return 0;
}