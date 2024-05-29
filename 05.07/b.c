#include "stdio.h"
#include "string.h"

int main() {
    char str[102], arr[102][102];
    int  maxLen = 0, j, k, i, p = 0;

    while (fgets(str, 102, stdin)) {
        if (str[0] == '\0') break;
        strtok(str, "\n");
        for (i = 0;i<102;i++) {
            if (i < strlen(str)) arr[p][i] = str[i];
            else arr[p][i] = ' ';
        }
        p++;
        if (strlen(str) > maxLen) maxLen = strlen(str);
    }

    for (j = 0;j<maxLen;j++) {
        for (k = p-1;k>=0;k--) {
            printf("%c", arr[k][j]);
        }
        printf("\n");
    }

    return 0;
}