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

int Palindrome(int n) {
    return n == reverseNumber(n);
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (Palindrome(number)) {
	printf("%d is a palindrome.\n", number);
    } else {
	printf("%d is not a palindrome.\n", number);
    }

    return 0;
}

