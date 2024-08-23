/* WAP to get Reverse of number n */
#include <stdio.h>

int reverseNumber(int n) {
    int reversed = 0, remainder;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    return reversed;
}

int main() {
    int number, reversed;

    printf("Enter an integer: ");
    scanf("%d", &number);

    reversed = reverseNumber(number);

    printf("Reversed number: %d\n", reversed);

    return 0;
}

