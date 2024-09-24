/* WAP to print factorial using malloc and free */

#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    unsigned long long *result = (unsigned long long *)malloc(sizeof(unsigned long long));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *result = factorial(number);
    printf("Factorial of %d = %llu\n", number, *result);

    free(result);
    return 0;
}

