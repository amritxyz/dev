#include <stdio.h>

int main(void)
{
    int num[3];
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num[0], &num[1], &num[2]);

    int max = num[0];
    if (num[1] > max) {
        max = num[1];
    }
    if (num[2] > max) {
        max = num[2];
    }
    printf("The greatest number is: %d\n", max);
}

