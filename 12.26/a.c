#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int isJolly(int* arr, int size) {
    int i, check[size];
    for (i = 0;i<size;i++) {
        check[i] = 0;
    }
    for (i = 0;i<size-1;i++) {
        int diff = abs(arr[i] - arr[i+1]);
        if (diff >= size || !diff || check[diff-1] == 1) return 0;
        check[diff-1] = 1;
    }

    return 1;
}

int main() {
    int n, i;
    int* input = malloc(sizeof(int));
    while (scanf("%d", &n) != EOF) {
        input = realloc(input, sizeof(int) * n);
        for (i = 0;i<n;i++) {
            scanf("%d", input + i);
        }
        printf("%s\n", isJolly(input, n) ? "Jolly" : "Not jolly");
    }
    free(input);
    input = NULL;

    return 0;
}