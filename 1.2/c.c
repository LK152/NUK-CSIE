#include "stdio.h"
#include "string.h"

int main() {
    int a = 1, b = 1000;
    char input[10];
    while (strcmp("correct\n", input)) {
        int guess = (a+b)/2;

        printf("%d\n", guess);
        fflush(stdout);

        fgets(input, 10, stdin);

        if (!strcmp("higher\n", input)) {
            a = guess+1;
        }

        if (!strcmp("lower\n", input)) {
            b = guess-1;
        }
    }

    return 0;
}