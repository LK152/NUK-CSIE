#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int volume;
    int value;
} bone_t;

// int max(int a, int b) {
//     if (a > b) return a;

//     return b;
// }

int main() {
    int t, i, j, k;
    scanf("%d", &t);
    for (i = 0;i<t;i++) {
        int n, v;
        scanf("%d %d", &n, &v);

        bone_t* bones = malloc(sizeof(bone_t) * n);
        int* dp = malloc(sizeof(int) * (v+1));

        for (j = 0;j<=v;j++) dp[j] = 0;

        for (j = 0;j<n;j++) {
            scanf("%d", &bones[j].value);
        }
        for (j = 0;j<n;j++) {
            scanf("%d", &bones[j].volume);
        }

        for (j = 0;j<n;j++) {
            for (k = v;k>=(bones + j)->volume;k--) {
                dp[k] = max(dp[k], dp[k-(bones + j)->volume] + (bones + j)->value);
            }
        }
        printf("%d\n", dp[v]);

        free(bones);
        free(dp);
        dp = NULL;
        bones = NULL;
    }

    return 0;
}