#include <stdio.h>
int countdigits(int num) {
    int count = 0;
    if (num == 0) {
        return 1;
    }
    if (num < 0) {
        num = -num;
    }
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
int main() {
    int n, count;
    printf("Enter an integer: ");
    scanf("%d", &n);
    count = countdigits(n);
    printf("Number of digits: %d\n", count);
    return 0;
}

