#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int value;
    int weight;
    double unit;
} item;

void swap(item* a, item* b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

int part(item* arr, int low, int high) {
    double pivot = (arr + high)->unit;
    int idx = low-1, i;

    for (i = low;i<high;i++) if (pivot >= (arr + i)->unit) swap((arr + (++idx)), (arr + i));

    swap(arr+idx+1, arr+high);

    return idx+1;
}

void qs(item* arr, int low, int high) {
    if (low > high) return;
    int pivot = part(arr, low, high);
    qs(arr, low, pivot-1);
    qs(arr, pivot+1, high);
}

int main() {
    int n, i;
    double max = 0, w;
    scanf("%d %lf", &n, &w);
    item* items = malloc(sizeof(item) * n);
    for (i = 0;i<n;i++) {
        scanf("%d %d", &(items + i)->value,  &(items + i)->weight);
        (items + i)->unit = (double) (items + i)->value / (items + i)->weight;
    }
    qs(items, 0, n-1);
    for (i = n-1;i>=0;i--) {
        if ((items + i)->weight <= w) {
            max += (items + i)->value;
            w -= (items + i)->weight;
        } else {
            max += (items + i)->value * w / (items + i)->weight;
            w = 0;
        }
    }
    printf("%f\n", max);

    free(items);
    items = NULL;

    return 0;
}