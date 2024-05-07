#include "stdio.h"
#include "string.h"

int main() {
    int p, k;
    char str[1000];
    fgets(str, 1000, stdin);
    for (int j = 0;j<strlen(str);j++) {
        p = j;
        for (;str[j] != ' '&& str[j] != '\0' && str[j] != '\n';j++);
        k = j-1;
        for (int l = k;l>=p;l--) putchar(str[l]);
        if (str[j] == ' ') putchar(' ');
    }

    return 0;
}