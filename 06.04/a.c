#include "stdio.h"

int main() {
    int b[3], g[3], c[3], moves[6], idx, i;
    char* order[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    while (scanf("%d", &b[0]) != EOF) {
        scanf("%d%d%d%d%d%d%d%d", &g[0], &c[0], &b[1], &g[1], &c[1], &b[2], &g[2], &c[2]);
        idx = 0;
        moves[0] = b[1] + b[2] + g[0] + g[1] + c[0] + c[2];
        moves[1] = b[1] + b[2] + g[0] + g[2] + c[0] + c[1];
        moves[2] = b[0] + b[2] + g[0] + g[1] + c[1] + c[2];
        moves[3] = b[0] + b[1] + g[0] + g[2] + c[1] + c[2];
        moves[4] = b[0] + b[2] + g[1] + g[2] + c[0] + c[1];
        moves[5] = b[0] + b[1] + g[1] + g[2] + c[0] + c[2];
        
        for (i = 1;i<6;i++) {
            if (moves[i] < moves[idx]) {
                idx = i;
            }
        }
        printf("%s %d\n", order[idx], moves[idx]);
    }
    

    return 0;
}