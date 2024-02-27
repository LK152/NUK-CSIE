#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int quickSum(char input[], int size) {
    int i, sum = 0;
    for (i = 0;i<size;i++) {
        if (input[i] != ' ') sum += (input[i]-64) * (i+1);
    }

    return sum;
}

int main() {
    char* input = malloc(300*sizeof(char));
    while (1) {
        fgets(input, 300, stdin);
        input[strcspn(input, "\n")] = 0;
        if (!strcmp(input, "#")) return 0;
        printf("%d\n", quickSum(input, strlen(input)));
    }
    free(input);
    input = NULL;

    return 0;
}