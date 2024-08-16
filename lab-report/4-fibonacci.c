// WAP to generate fibonacci series using functions
#include <stdio.h>

void Fibonacci(int n) {

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }

    int a = 0, b = 1;

    printf("Fibonacci Series:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", a);

        int next = a + b;
        a = b;
        b = next;
    }

    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    Fibonacci(n);
    return 0;
}

