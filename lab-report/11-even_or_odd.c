/* WAP to find the number is odd or even */
#include <stdio.h>

int Even(int number) {
    return (number % 2 == 0);
}

void EvenOrOdd(int number) {
    if (Even(number)) {
        printf("The number %d is Even.\n", number);
    } else {
        printf("The number %d is Odd.\n", number);
    }
}

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    EvenOrOdd(num);

    return 0;
}

