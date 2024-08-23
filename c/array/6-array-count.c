/* WAP to count a element in array */
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = 2;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            count++;
        }
    }

    printf("Element %d repeats %d times in the array.\n", element, count);

    return 0;
}

