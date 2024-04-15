#include "stdio.h"

int canPass(int* xLvls, int* yLvls, int n, int xSize, int ySize) {
    int lvls[n+1], i;
    for (i = 1;i<=n;i++) {
        lvls[i] = 0;
    }
    for (i = 0;i<xSize;i++) {
        lvls[xLvls[i]] = 1;
    }
    for (i = 0;i<ySize;i++) {
        lvls[yLvls[i]] = 1;
    }

    for (i = 1;i<=n;i++) {
        if (!lvls[i]) return 0;
    }

    return 1;
}

int main() {
    int n, i, p, l;

    scanf("%d", &n);

    scanf("%d", &p);
    int x[p];
    for (i = 0;i<p;i++) {
        scanf("%d", &x[i]);
    }

    scanf("%d", &l);
    int y[l];
    for (i = 0;i<l;i++) {
        scanf("%d", &y[i]);
    }
    
    printf("%s", canPass(x, y, n, p, l) ? "I become the guy." : "Oh, my keyboard!");

    return 0;
}