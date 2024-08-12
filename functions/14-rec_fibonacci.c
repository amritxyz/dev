#include <stdio.h>

void fibonacci(int n, int a, int b);

int main() {
    int a = 10;
    printf("Fibonacci series up to %d: ", a);
    fibonacci(a, 0, 1);
    return 0;
}

void fibonacci(int n, int a, int b) {
    if (n <= 0) {
        return;
    }

    printf("%d ", a);
    fibonacci(n - 1, b, a + b);
}

