#include <stdio.h>

int fibonacci(int n);

int main() {
    int number = 10;
    printf("Fibonacci number at position %d is %d\n", number, fibonacci(number));
    return 0;
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

