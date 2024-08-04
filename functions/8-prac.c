#include <stdio.h>

// Function declaration with pointer parameters
void updateValues(int *a, int *b);

int main() {
    int a, b;
    int originalA, originalB;

    // Prompt user for input
    printf("Enter 2 numbers which you want to modify: ");
    scanf("%d%d", &a, &b);

    // Store the original values
    originalA = a;
    originalB = b;

    // Call function to update values
    updateValues(&a, &b);

    // Print original values
    printf("Original values: a = %d, b = %d\n", originalA, originalB);

    // Print updated values
    printf("Updated values: a = %d, b = %d\n", a, b);

    return 0;
}

// Function definition
void updateValues(int *a, int *b) {
    *a = *a + 10;  // Modify the value pointed to by 'a'
    *b = *b + 20;  // Modify the value pointed to by 'b'
}

