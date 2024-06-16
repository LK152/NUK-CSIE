#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main() {
    int a, b, ans, guess, lower, upper;
    srand(time(NULL));

    scanf("%d %d", &a, &b);

    ans = a + (rand()%b);

    lower = a;
    upper = b;

    while (1) {
        scanf("%d", &guess);
        
        if (guess == ans) {
            printf("correct");
            return 0;
        }

        if (guess < lower || guess > upper) {
            printf("num not in range\n");
        } else if (guess < ans) {
            printf("higher\n");
            lower = guess + 1;
        } else if (guess > ans) {
            printf("lower\n");
            upper = guess - 1;
        }
        
        printf("%d~%d\n", lower, upper);
    }


    return 0;
}