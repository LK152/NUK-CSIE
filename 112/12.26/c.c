#include "stdio.h"
#include "string.h"

void encode(char* str, int len, int k) {
    int i;
    for (i = 0;i<len+1;i++) {
        if (str[i]+k > 90) str[i] = 64 + (str[i]+k-90);
        else str[i] += k;
    }
}

int main() {
    char input[30];
    while (scanf("%s", input) != EOF) {
        int k, i, t;
        scanf("%d", &k);
        int len = strlen(input);
        encode(input, len, k);
        for (i = 0;i<len;i++) {
            scanf("%d", &t);
            printf("%c", input[t-1]);
        }
        printf("\n");
    }

    return 0;
}