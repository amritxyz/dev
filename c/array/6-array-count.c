/* WAP to count a element in array */
// #include <stdio.h>
//
// int main() {
//     int arr[] = {1, 2, 3, 4, 2, 5, 2, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int element = 2;
//     int count = 0;
//
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == element) {
//             count++;
//         }
//     }
//
//     printf("Element %d repeats %d times in the array.\n", element, count);
//
//     return 0;
// }
//
#include <stdio.h>

int main() {
    int n;

    // Ask user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declare an array with the user-defined size
    int arr[n];

    // Read array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the element to count
    int element;
    printf("Enter the element to count: ");
    scanf("%d", &element);

    // Count occurrences of the element
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            count++;
        }
    }

    // Print the result
    printf("Element %d repeats %d times in the array.\n", element, count);

    return 0;
}

