/* WAP to find student's Total and Average marks in 5 subjects */
#include <stdio.h>

int main() {
    int arr[5];
    int sum = 0;
    float average;

    printf("Enter 5 subject marks:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    average = (float)sum / 5;

    printf("Total sum of the 5 numbers is: %d\n", sum);
    printf("The average of the 5 numbers is: %.2f\n", average);

    return 0;
}

