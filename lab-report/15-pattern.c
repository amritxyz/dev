#include <stdio.h>

int main() {
    int i, j, k;
    const char n = '*';
    int rows = 5;

    for (i = 1; i <= rows; i++) {
        for (k = rows; k > i; k--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("%c", n);
        }
        printf("\n");
    }
    return 0;
}

