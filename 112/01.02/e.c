#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

int isPrime(int n) {
    if (n == 0 || n == 1) return 0;
    int i;
    for (i = 2;i<=n/2;i++) {
        if (!(n%i)) return 0;
    }

    return 1;
}

int main() {
    int check[26], num;
    char input[100];
    scanf("%s", input);
    int len = strlen(input), i;
    for (i = 0;i<26;i++) {
        check[i] = 0;
    }
    for (i = 0;i<len;i++) {
        check[input[i]-'a']++;
    }
    bubbleSort(check, 26);
    for(i = 0;i<26;i++) {
        if (!check[i]) continue;
        num = check[25] - check[i];
        break;
    }

    printf("%s\n", isPrime(num) ? "Lucky Word" : "No Answer");
    printf("%d\n", isPrime(num) ? num : 0);

    return 0;
}