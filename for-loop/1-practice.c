#include <stdio.h>
int main() {
    int n = 10;
    int first = 1, second = 1, next;
    printf("Fibonacci numbers: ");
    printf("%d %d ", first, second);
    for (int i = 3; i <= n; ++i) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
    printf("\n");
    return 0;
}
// Fibonacci numbers: 1 1 2 3 5 8 13 21 34 55
