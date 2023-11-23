#include "stdio.h"

int func (int a, int b, int c, int x) {
    return a*x*x + b*x + c;
}

int main () {
    int a, b, c, d, l, i;

    while (1) {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &l);

        if (!a && !b && !c && !d && !l) return 0;

        int cnt = 0;

        for (i = 0;i<=l;i++) {
            if (!(func(a, b, c, i)%d)) cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}