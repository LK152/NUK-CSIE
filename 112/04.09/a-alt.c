#include "stdio.h"

int canPass(int* arr, int size) {
    int i;
    for (i = 1;i<=size;i++) {
        if (!arr[i]) return 0;
    }

    return 1;
}

int main() {
    int n, i, p, l;

    scanf("%d", &n);
    int lvls[n+1];
    for (i = 1;i<=n;i++) {
        lvls[i] = 0;
    }

    scanf("%d", &p);
    int x;
    for (i = 0;i<p;i++) {
        scanf("%d", &x);
        lvls[x] = 1;
    }

    scanf("%d", &l);
    int y;
    for (i = 0;i<l;i++) {
        scanf("%d", &y);
        lvls[y] = 1;
    }
    
    printf("%s", canPass(lvls, n) ? "I become the guy." : "Oh, my keyboard!");

    return 0;
}