#include "stdio.h"

int main() {
    int y;
    scanf("%d", &y);
    if (!(y%400)) printf("Yes");
    else if (!(y%100)) printf("No");
    else if (!(y%4)) printf("Yes");
    else printf("No");
    
    return 0;
}