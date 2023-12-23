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

int binarySearch(int* arr, int size, int num, int startIdx, int endIdx) {
    if (startIdx > endIdx) return 0;

    int mid = floor((startIdx + endIdx)/2);

    if (num == arr[mid]) return 1;

    if (num > arr[mid]) return binarySearch(arr, size, num, mid+1, endIdx);
    
    if (num < arr[mid]) return binarySearch(arr, size, num, startIdx, mid-1);
}

void isFound(int* arr, int size, int num) {
    int i;

    for (i = 0;i<size;i++) {
        if (arr[i] == num) arr[i] = 0;
    }
}

int main() {
    int n, i, cnt = 0, flag = 1;
    scanf("%d", &n);

    int* input = malloc(sizeof(int) * n);
    int* copy = malloc(sizeof(int) * n);

    for (i = 0;i<n;i++) {
        scanf("%d", input+i);
        *(copy + i) = *(input + i);
    }

    bubbleSort(input, n);

    while (flag) {
        int x;
        scanf("%d", &x);

        printf("%d %s\n", x, binarySearch(input, n, x, 0, n-1) ? "found" : "not found");
        if (binarySearch(input, n, x, 0, n-1)) {
            isFound(copy, n, x);
        }

        for (i = 0;i<n;i++) {
            if (copy[i]) {
                flag = 1;
                break;
            }
            flag = 0;
        }
    }

    free(input);
    free(copy);
    input = NULL;
    copy = NULL;
    
    return 0;
}