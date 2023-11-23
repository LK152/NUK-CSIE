#include "stdio.h"

void swap (int* a, int* b) {
    int x;
    x = *a;
    *a = *b;
    *b = x;
}

int main () {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    swap(&a, &b);
    swap(&a, &c);

    printf("%d %d %d", a, b, c);

    return 0;
}