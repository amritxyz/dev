// Example of call by Reference
#include <stdio.h>

void callByReference(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);

    callByReference(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}

