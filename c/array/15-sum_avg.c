#include <stdio.h>

// Function to read 'n' numbers into an array
void readArray(int arr[], int n) {
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
}

// Function to calculate the sum of the elements in the array
int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of the elements in the array
double calculateAverage(int arr[], int n) {
    if (n == 0) return 0; // Avoid division by zero
    int sum = calculateSum(arr, n);
    return (double)sum / n;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of elements must be positive.\n");
        return 1; // Exit the program with an error code
    }

    int arr[n]; // Declare an array of size 'n'

    // Read numbers into the array
    readArray(arr, n);

    // Calculate sum and average
    int sum = calculateSum(arr, n);
    double average = calculateAverage(arr, n);

    // Display results
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}

