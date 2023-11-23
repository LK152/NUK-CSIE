#include "stdio.h"

int main() {
    int e, f, c, ans = 0;

    scanf("%d %d %d", &e, &f, &c);
    e += f;
    while (e/c) {
        ans += e/c;
        e = e/c + e%c;
    }

    printf("%d", ans);

    return 0;
}