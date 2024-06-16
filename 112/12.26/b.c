#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void bubbleSort(int* arr, int size) {
    int temp, i, j, cnt = size-1;

    for (i = 0;i<size-1;i++) {
        for (j = 0;j<cnt;j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        cnt--;
    }
}

int main() {
    int n, i, j;
    scanf("%d", &n);
    for (i = 0;i<n;i++) {
        int a;
        scanf("%d", &a);
        int rel[a];
        for (j = 0;j<a;j++) {
            scanf("%d", &rel[j]);
        }
        bubbleSort(rel, a);
        int k = floor(a/2), sum = 0;
        for (j = 0;j<a;j++) {
            sum += abs(rel[k] - rel[j]);
        }

        printf("%d\n", sum);
    }

    return 0;
}