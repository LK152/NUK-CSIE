#include "stdio.h"

int min(int a, int b) {
    if (a > b) return b;
    
    return a;
}

int max(int a, int b) {
    if (a > b) return a;
    
    return b;
}

int opCount(int num) {
    int cnt = 1;
    while (num != 1) {
        cnt++;
        if (num%2) num = 3*num + 1;
        else num /= 2;
    }

    return cnt;
}

int main() {
    int a, b, i;
    while (scanf("%d %d", &a, &b) != EOF) {
        int ans = 0;
        for (i = min(a, b);i<=max(a, b);i++) {
            ans = max(ans, opCount(i));
        }
        printf("%d %d %d\n", a, b, ans);
    }

    return 0;
}