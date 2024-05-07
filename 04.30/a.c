#include "stdio.h"
#include "string.h"

int main() {
    int n;
    char str[1000];

    scanf("%d", &n);
    getchar();
    for (int i = 0;i<n;i++) {
        int p, k;
        gets(str);
        for (int j = 0;j<strlen(str);j++) {
            p = j;
            for (;str[j] != ' '&& str[j] != '\0';j++);
            k = j-1;
            for (int l = k;l>=p;l--) putchar(str[l]);
            if (str[j] == ' ') putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}