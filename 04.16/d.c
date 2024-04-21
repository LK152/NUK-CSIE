#include "stdio.h"
#include "stdlib.h"

int fib(int n) {
    if (!n || n == 1) return n;
    
    return fib(n-1) + fib(n-2);
}

int main() {
    int n, i, j;
    scanf("%d", &n);
    int* input = malloc(sizeof(int) * n);
    int* fibs = malloc(sizeof(int)* 40);
    for (i = 0;i<40;i++) {
        fibs[i] = fib(i);
    }
    for (i = 0;i<n;i++) {
        scanf("%d", input + i);
    }
    
    for (i = 0;i<n;i++) {
        int flg = 0;
        printf("%d = ", *(input + i));
        for (j = 39;j>1;j--) {
            if (input[i] >= fibs[j]) {
                input[i] -= fibs[j];
                putchar('1');
                flg = 1;
            } else if (flg) putchar('0');
        }
        printf(" (fib)\n");
    }

    free(input);
    input = NULL;
    free(fibs);
    fibs = NULL;

    return 0;
}