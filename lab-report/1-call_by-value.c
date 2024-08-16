// Example of call by value
#include <stdio.h>

void callByValue(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);

    callByValue(x, y);

    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}

