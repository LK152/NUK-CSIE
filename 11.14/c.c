#include "stdio.h"
#include "stdlib.h"

int main() {
    int a, size = 1, idx = 0;
    int *arr = malloc(sizeof(int));
    scanf("%d", &a);

    while (a) {
        if (a/8) arr = realloc(arr, sizeof(int) * ++size);
        *(arr + idx++) = a%8;
        a /= 8;
    }

    for (int i = size-1;i>=0;i--) {
        printf("%d", *(arr+i));
    }
    
    free(arr);
    arr = NULL;

    return 0;
}