/* WAP to find whether the number is odd or even using recursive. */
#include <stdio.h>

int even(int num) {

    if (num == 0) {
        return 1; // Even
    }

    if (num == 1) {
        return 0; // Odd
    }

    return even(num - 2);
}

void check(int num) {
    if (even(num)) {
        printf("The number %d is Even.\n", num);
    } else {
        printf("The number %d is Odd.\n", num);
    }
}

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    check(num);

    return 0;
}

