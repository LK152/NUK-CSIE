#include "stdio.h"

int main() {
    int n, i, amazing = 0;
    scanf("%d", &n);
    int in[n];
    for (i = 0;i<n;i++) {
        scanf("%d", in+i);
    }
    int worst = in[0], best = in[0];
    for (i = 1;i<n;i++) {
        if (*(in + i) > best) {
            amazing++;
            best = *(in + i);
        }
        if (*(in + i) < worst) {
            amazing++;
            worst = *(in + i);
        }
    }
    printf("%d", amazing);

    return 0;
}