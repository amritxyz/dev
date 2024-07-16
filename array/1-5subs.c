#include <stdio.h>
int main() {
    int marks[5];
    int i, total = 0;
    float avg;
    printf("Enter marks for 5 subjects:\n");
    for (i = 0; i < 5; ++i) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];
    }
    avg = (float)total / 5.0;
    printf("Total marks: %d\n", total);
    printf("Average marks: %.2f\n", avg);
    if (avg >= 80) {
        printf("Topper\n");
    } else if (avg >= 60) {
        printf("First division\n");
    } else if (avg >= 50) {
        printf("Second division\n");
    } else {
        printf("Fail\n");
    }
    return 0;
}

