#include <stdio.h>

#define small 80

int main()
{
	int units;
	float bill_amt;
	printf("Enter the units consumed: ");
	fflush(stdout);
	scanf("%d", &units);

	if (units <= 20) {
		bill_amt = small;
		bill_amt += bill_amt * 0.15;
	}
	else if (units <= 100) {
		bill_amt = small;
		bill_amt += (units - 20) * 8.0;
		bill_amt += bill_amt * 0.15;
	}
	else if (units <= 200) {
		bill_amt = small;
		bill_amt += (units - 20) * 4.0;
		bill_amt += (units - 100) * 10.0;
		bill_amt += bill_amt * 0.15;
	}
	else {
		bill_amt = 20 * 4.0;
		bill_amt += (units - 20) * 4.0;
		bill_amt += (units - 100) * 10.0;
		bill_amt += units * 12.0;
		bill_amt += bill_amt * 0.15;
	}
	printf("Total rs: %f\n", bill_amt);

	return 0;
}

