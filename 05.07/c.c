#include "stdio.h"

int main() {
    int i, pair = 0;
    char input;

    while (scanf("%c", &input) != EOF) {
        if (input == '"') {
            printf("%s", pair ? "''" : "``");
            pair = pair ? 0 : 1;
            continue;
        }
        putchar(input);
    }

    return 0;
}