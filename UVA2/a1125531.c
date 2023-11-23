#include "stdio.h"
#include "stdlib.h"

int min(int a, int b) {
    if (a < b) return a;
    
    return b;
}

int uglyNumber(int n) {
    int i, idx2 = 0, idx3 = 0, idx5 = 0;
    int ugly2 = 2, ugly3 = 3, ugly5 = 5, ugly_num = 1;
    int* arr = (int*)malloc(sizeof(int) * n);
    *arr = ugly_num;

    for (i = 1;i<n;i++) {
        ugly_num = min(min(ugly2, ugly3), ugly5);
        *(arr + i) = ugly_num;
        if (ugly_num == ugly2) {
            ugly2 = *(arr + (++idx2)) * 2;
        }
        if (ugly_num == ugly3) {
            ugly3 = *(arr + (++idx3)) * 3;
        }
        if (ugly_num == ugly5) {
            ugly5 = *(arr + (++idx5)) * 5;
        }
    }
    
    int ans = *(arr + (n-1));

    free(arr);
    arr = NULL;

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", uglyNumber(n));

    return 0;
}