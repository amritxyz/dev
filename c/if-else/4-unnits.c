#include <stdio.h>

int main()
{
    int units;
    float bill_amount;
    printf("Enter the units consumed: ");
    fflush(stdout);
    scanf("%d", &units);
    if (units <= 100) {
        bill_amount = units * 5.0;
    }
    else {
        bill_amount = 100 * 5.0;
	if (units >= 100 && units <= 300) {
            bill_amount += (units - 100) * 7.0;
        }
	else if (units > 300) {
		bill_amount = (100*5)+(200*7);
		bill_amount += (units-300) * 9;
	}
    }
	/* else{ */
	/* bill_amount = (100*5.0)+(200*7.0); */
	/* bill_amount += (units - 300) * 9; */
/* } */
	bill_amount += 150.0;
	printf("Total electricity bill: Rs. %f\n", bill_amount);
   	return 0;
}

