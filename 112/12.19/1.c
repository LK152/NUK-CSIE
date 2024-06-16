#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

int unique(int* arr, int size, int number) {
    int i;

    for (i = 0;i<size;i++) {
        if (number == arr[i]) return 0;
    }

    return 1;
}

int find(int* arr, int size, int number) {
    int i;

    for (i = 0;i<size;i++) {
        if (number == arr[i]) return i;
    }

    return 0;
}

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
    srand(time(NULL));
    int randoms[50], i;
    for (i = 0;i<50;i++) {
        while (1) {
            int number = 1 + (rand()%100);

            if (!unique(randoms, i+1, number)) continue;
            else {
                randoms[i] = number;
                break;
            }
        }
    }

    bubbleSort(randoms, 50);

    for (i = 0;i<50;i++) {
        printf("%d", randoms[i]);
        if (i != 49) printf(" ");
        else printf("\n");
    }

    int ans = randoms[rand()%50], lower = randoms[0], upper = randoms[49], lowerIdx = 0, upperIdx = 49;

    printf("%d~%d\n", lower, upper);
    
    while (1) {
        int mid = floor((upperIdx + lowerIdx)/2);
        int guess = randoms[mid];

        printf("Auto guess: %d\n", guess);

        if (guess == ans) {
            printf("correct");
            return 0;
        }

        if (!find(randoms, 50, guess)) {
            printf("num not in range\n");
        } else if (guess < ans) {
            printf("higher\n");
            lower = guess;
            lowerIdx = find(randoms, 50, guess);
        } else if (guess > ans) {
            printf("lower\n");
            upper = guess;
            upperIdx = find(randoms, 50, guess);
        }

        printf("%d~%d\n", lower, upper);
    }

    return 0;
}