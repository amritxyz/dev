#include <stdio.h>
int main() {
    int units;
    float bill_amount;
    printf("Enter the units consumed: ");
    scanf("%d", &units);
    if (units <= 50) {
        bill_amount = units * 5.0;
    } else {
        bill_amount = 50 * 5.0;

        if (units > 50) {
            bill_amount += (units - 50) * 7.0;
        }
    }
    bill_amount += 150.0;
    printf("Total electricity bill: Rs. %.2f\n", bill_amount);
    return 0;
}

