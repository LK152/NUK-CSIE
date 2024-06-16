#include "stdio.h"

int main () {
    int a;

    scanf("%d", &a);

    if (!(a%3200)) printf("N");
    else if (!(a%400)) printf("Y");
    else if (!(a%100)) printf("N");
    else if (!(a%4)) printf("Y");
    else printf("N");

    return 0;
}