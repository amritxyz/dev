#include <stdio.h>

int main()
{
    int search, a[5], size, flag = 0;

    printf("Enter the number of elements (max 5): ");
    scanf("%d", &size);

    if (size > 5) {
        printf("Size cannot be greater than 5.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &search);

    for (int i = 0; i < size; i++) {
        if (a[i] == search) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("The number is available.\n");
    } else {
        printf("The number is not available.\n");
    }

    return 0;
}

