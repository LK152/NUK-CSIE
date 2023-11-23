#include "stdio.h"

int isEven (int n) {
    if (n == 2) return 0;
    if (n%2) return 0;

    return 1;
}

int main () {
    int n;
    
    scanf("%d", &n);

    if (isEven(n)) printf("YES");
    else printf("NO");

    return 0;
}