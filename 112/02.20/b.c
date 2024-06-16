#include "stdio.h"
#include "string.h"

int main() {
    int x;

    while (1) {
        scanf("%d", &x);
        if (!x) return 0;
        int i, n = 2, s = 5, e = 4, w = 3, top = 1, btm = 6;
        char input[6];
        for (i = 0;i<x;i++) {
            scanf("%s", input);
            if (!strcmp("north", input)) {
                btm = n;
                n = top;
                s = 7-n;
            }
            if (!strcmp("south", input)) {
                btm = s;
                s = top;
                n = 7-s;
            }
            if (!strcmp("east", input)) {
                btm = e;
                e = top;
                w = 7-e;
            }
            if (!strcmp("west", input)) {
                btm = w;
                w = top;
                e = 7-w;
            }
            top = 7-btm;
        }
        printf("%d\n", top);
    }

    return 0;
}