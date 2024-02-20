#include "stdio.h"
#include "math.h"

int binarySearch(int* arr, int size, int startIdx, int endIdx, int num) {
    if (startIdx > endIdx) return 0;

    int mid = floor((startIdx + endIdx)/2);

    if (num == arr[mid]) return 1;

    if (num > arr[mid]) return binarySearch(arr, size, mid+1, endIdx, num);
    
    if (num < arr[mid]) return binarySearch(arr, size, startIdx, mid-1, num);

    return 0;
}

int main() {
    int n, i, q;
    scanf("%d", &n);
    int input[n];
    for (i = 0;i<n;i++) {
        scanf("%d", &input[i]);
    }
    scanf("%d", &q);
    for (i = 0;i<q;i++) {
        int k;
        scanf("%d", &k);
        printf("%d\n", binarySearch(input, n, 0, n-1, k) ? 1 : 0);
    }

    return 0;
}