#include "stdio.h"

int main() {
    int n;
    while (1) {
        int i = 1;
        scanf("%d", &n);
        if (!n) return 0;
        if (n%2 || n == 2) {
            printf("Impossible\n");
            continue;
        }
        printf("%d\n", n/2 + n);
        if (n%4) {
            printf("1 2\n");
            printf("1 3\n");
            printf("1 4\n");
            printf("2 5\n");
            printf("2 6\n");
            printf("3 4\n");
            printf("3 5\n");
            printf("4 6\n");
            printf("5 6\n");
            i = 7;
        }
        for (;i<=n;i+=4) {
            printf("%d %d\n",i,i+1);
            printf("%d %d\n",i,i+2);
            printf("%d %d\n",i,i+3);
            printf("%d %d\n",i+1,i+2);
            printf("%d %d\n",i+1,i+3);
            printf("%d %d\n",i+2,i+3);
        }
    }


    return 0;
}