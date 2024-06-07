#include "stdio.h"
#include "string.h"

int main() {
    char str1[10000000], str2[10000000];
    while (scanf("%s %s", str1, str2) != EOF) {
        int len1 = strlen(str1), len2 = strlen(str2), i, j = 0;
        if (len1 > len2) {
            printf("No\n");
            continue;
        }

        for (i = 0;i<len2;i++) {
            if (str1[j] == str2[i]) j++;
        }
        printf("%s\n", j == len1 ? "Yes" : "No");
    }


    return 0;
}