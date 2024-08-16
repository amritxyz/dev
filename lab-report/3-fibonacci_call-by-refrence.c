#include <stdio.h>

// Function to calculate Fibonacci number using call by reference
void fibonacci(int n, int *result) {
    if (n == 0) {
        *result = 0;
    } else if (n == 1) {
        *result = 1;
    } else {
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        *result = b;
    }
}

int main() {
    int n = 10; // The index of the Fibonacci sequence to calculate
    int result;

    fibonacci(n, &result);

    printf("Fibonacci number at index %d is %d\n", n, result);
    return 0;
}

