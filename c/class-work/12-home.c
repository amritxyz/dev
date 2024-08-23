//wap to input the number find the sum of even number
#include <stdio.h>

int main() {
    int n, f, l, a;
    printf("Enter a number: ");
    scanf("%d", &n);
    l = n % 10;
    a = n;
    while (a >= 10) {
        a = a / 10;
    }
    f = a;
    int sum = f + l;
    printf("Sum of first and last digit: %d\n", sum);
    return 0;
}

