#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int value;
    int weight;
} item;

int max(int a, int b) {
    if (a > b) return a;

    return b;
}

int main() {
    int n, w, i, j;
    
    scanf("%d %d", &n, &w);
    int dp[w+1];
    item* items = malloc(sizeof(item) * n);
    for (i = 0;i<n;i++) {
        scanf("%d %d", &(items + i)->value, &(items + i)->weight);
    }
    for (i = 0;i<=w;i++) dp[i] = 0;
    for (i = 0;i<n;i++) {
        for (j = w;j>=(items + i)->weight;j--) {
            dp[j] = max(dp[j], dp[j-(items + i)->weight] + (items + i)->value);
        }
    }

    printf("%d\n", dp[w]);

    free(items);
    items = NULL;

    return 0;
}