#include "stdio.h"

int main () {
    int n, i;

    scanf("%d", &n);

    for (i = 1;i<=n;i++) {
        int a, b;

        scanf("%d %d", &a, &b);

        if (!(a%2) || !a) a++;
        if (!(b%2)) b--;

        printf("Case %d: %d\n", i, (((b-a)/2)+1)*(a+b)/2);
    }

    return 0;
}