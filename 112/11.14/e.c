#include "stdio.h"
#include "string.h"

int main() {
    int open = 0, pair = 0;
    char s[1000000];
    scanf("%s", s);
    for (int i = 0;i<strlen(s);i++) {
        if (s[i] == '(') {
            open++;
            continue;
        }
        if (s[i] == ')') {
            if (open) {
                pair++;
                open--;
            }
            continue;
        }
        if (s[i] == '\0') break;
    }
    printf("%d", pair*2);

    return 0;
}