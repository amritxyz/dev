#include <stdio.h>

int main() {
    int a = 9;
    for (int x = 0; x < 100; x++) {
        if (x % 2 == 0)
            continue;
        else
            a += x;
    }
    printf("The final value of a is: %d\n", a);
    return 0;
}

