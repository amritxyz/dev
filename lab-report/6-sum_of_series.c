#include <stdio.h>

// Function to generate Fibonacci series and compute the sum using call by reference
void Fibonacci(int n, int *series, int *sum) {
    if (n <= 0) {
        *sum = 0;
        return; // No terms to generate
    }

    // Initialize the first two terms
    if (n > 0) series[0] = 0;
    if (n > 1) series[1] = 1;

    // Compute the rest of the series
    *sum = series[0] + series[1]; // Initialize sum with the first two terms
    for (int i = 2; i < n; i++) {
        series[i] = series[i - 1] + series[i - 2];
        *sum += series[i]; // Add the current term to the sum
    }
}

int main() {
    int n = 10; // Number of terms in the Fibonacci series
    int series[n]; // Array to store the Fibonacci series
    int sum; // Variable to store the sum of the series

    Fibonacci(n, series, &sum);

    printf("Fibonacci series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", series[i]);
    }
    printf("\n");

    printf("Sum of the series: %d\n", sum);

    return 0;
}

